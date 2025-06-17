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

    def start_interpolation_absolute(self, start_pose, target_pose, steps=100):
        self.pose_queue = []
        for i in range(1, steps + 1):
            interp_pose = [(1 - i / steps) * start_pose[j] + (i / steps) * target_pose[j] for j in range(6)]
            self.pose_queue.append(interp_pose)
        self.interpolating = True

    def start_interpolation_relative(self, pose_delta, steps=100):
        pos_start = np.array(self.current_pose[:3])
        rpy_start = np.array(self.current_pose[3:])
        delta_pos = np.array(pose_delta[:3])
        delta_rpy = np.array(pose_delta[3:])
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