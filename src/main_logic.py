import numpy as np
from scipy.spatial.transform import Rotation as R

class StewartController:
    def __init__(self):
        self.enabled = False
        self.stopped = False
        self.interpolating = False
        self.pose_queue = []
        self.current_pose = [0.0] * 6
        self.leg_lengths = [0.0] * 6
        self.status = 0
        self.max_delta_length = 180
        self.max_length = [351.8245358903903+self.max_delta_length,353.2537476348852+self.max_delta_length,353.17962646484375+self.max_delta_length,
                            352.8763122558594+self.max_delta_length,352.6863098144531+self.max_delta_length,353.7471923828125+self.max_delta_length]

    def process_command(self, data):
        if len(data) < 9:
            return
        cmd = int(data[0])
        subcmd1 = int(data[1])
        subcmd2 = int(data[2])
        pose = list(data[3:9])
        if cmd == 1:
            self.enabled = True
            self.status = 1
            print("initialized!")
        elif cmd == 2:
            self.enabled = False
            self.interpolating = False
            self.status = 0
        elif cmd == 3 and self.enabled: # 回零
            self.status = 2
            pose = [0.0] * 6
            self.start_interpolation_absolute(self.current_pose, pose)
            print("Ressting current pose to zero.")
        elif cmd == 4 and self.enabled:
            self.status = 3
            if subcmd1 == 1:
                self.start_interpolation_absolute(self.current_pose, pose)
                print("Starting absolute interpolation to pose:", pose)
            elif subcmd1 == 2:
                self.start_interpolation_relative(pose)
                print("Starting relative interpolation with delta:", pose)
        elif cmd == 5 and self.enabled: # 对准
            self.start_interpolation_absolute(self.current_pose, pose)
            self.status = 4
        elif cmd == 6: # 停止运动
            self.stopped = True
            self.interpolating = False
            self.status = 5
            print("Interpolation stopped.")
        elif cmd == 7:
            self.stopped = False
            print("Interpolation resumed.")
            if self.pose_queue:
                self.interpolating = True
        elif cmd == 8:
            # TODO:对准，与定义多个标记物
            print("对准")

    def start_interpolation_absolute(self, start_pose, target_pose, velocity=0.01, angular_velocity=0.1):
        """
        绝对定位插值，运动时间与距离成正比
        
        Args:
            start_pose: 起始位姿 [x, y, z, rx, ry, rz]
            target_pose: 目标位姿 [x, y, z, rx, ry, rz]  
            velocity: 线性速度 (单位/步)
            angular_velocity: 角速度 (弧度/步)
        """
        # 计算位置距离
        pos_distance = np.linalg.norm(np.array(target_pose[:3]) - np.array(start_pose[:3]))
        
        # 计算姿态距离 (欧拉角差的模长)
        rpy_distance = np.linalg.norm(np.array(target_pose[3:]) - np.array(start_pose[3:]))
        
        # 根据距离和速度计算步数
        pos_steps = int(pos_distance / velocity) if velocity > 0 else 1
        rpy_steps = int(rpy_distance / angular_velocity) if angular_velocity > 0 else 1
        
        # 取较大的步数确保运动平滑
        steps = max(pos_steps, rpy_steps, 1)
        
        self.pose_queue = []
        for i in range(1, steps + 1):
            interp_pose = [(1 - i / steps) * start_pose[j] + (i / steps) * target_pose[j] for j in range(6)]
            self.pose_queue.append(interp_pose)
        self.interpolating = True

    def start_interpolation_relative(self, pose_delta, velocity=0.01, angular_velocity=0.1):
        """
        相对定位插值，运动时间与距离成正比
        
        Args:
            pose_delta: 相对位姿变化 [dx, dy, dz, drx, dry, drz]
            velocity: 线性速度 (单位/步)
            angular_velocity: 角速度 (弧度/步)
        """
        pos_start = np.array(self.current_pose[:3])
        rpy_start = np.array(self.current_pose[3:])
        delta_pos = np.array(pose_delta[:3])
        delta_rpy = np.array(pose_delta[3:])
        
        # 计算位置和姿态的变化距离
        pos_distance = np.linalg.norm(delta_pos)
        rpy_distance = np.linalg.norm(delta_rpy)
        
        # 根据距离和速度计算步数
        pos_steps = int(pos_distance / velocity) if velocity > 0 else 1
        rpy_steps = int(rpy_distance / angular_velocity) if angular_velocity > 0 else 1
        
        # 取较大的步数确保运动平滑
        steps = max(pos_steps, rpy_steps, 1)
        
        delta_pos_step = delta_pos / steps
        delta_rpy_step = delta_rpy / steps
        
        self.pose_queue = []
        for i in range(1, steps + 1):
            pos_i = pos_start + i * delta_pos_step
            rpy_i = rpy_start + i * delta_rpy_step
            rot_i = R.from_euler('xyz', rpy_i)
            euler_i = rot_i.as_euler('xyz')
            pose_i = list(pos_i) + list(euler_i)
            self.pose_queue.append(pose_i)
        self.interpolating = True

    def step_interpolation(self):
        if self.interpolating and not self.stopped:
            if self.pose_queue:
                next_pose = self.pose_queue.pop(0)
                self.current_pose = next_pose
                return next_pose
            else:
                self.interpolating = False
        return None

    def update_leg_lengths(self, lengths):
        self.leg_lengths = lengths
        # TODO: 检查每条腿的长度是否超过限制
        # for i, length in enumerate(lengths):
        #     if length > self.max_length:
        #         print(f"Warning: Leg {i+1} length {length} exceeds limit {self.max_leg_length}")
        #         # 设置状态为6表示达到限位
        #         self.status = 6
        #         # 停止插值
        #         #self.interpolating = False
        #         #self.stopped = True
        #         # 清空待执行的位姿队列，目标位姿设为当前位姿
        #         self.pose_queue = []
        #         print("Interpolation stopped due to leg length limit exceeded.")
        #         break

    def get_feedback(self):
        # 返回14项：count, status, 0, x, y, z, roll, yaw, pitch, l1~l6
        pose = self.current_pose
        feedback = [self.status] + pose + self.leg_lengths
        return feedback

if __name__ == "__main__":
    controller = StewartController()
    # 示例命令处理
    controller.process_command([1, 0, 0, 0.1, 0.2, 0.3, 0.0, 0.0, 0.0])
    print("Current Pose:", controller.current_pose)
    print("Leg Lengths:", controller.leg_lengths)
    feedback = controller.get_feedback()
    print("Feedback:", feedback)
