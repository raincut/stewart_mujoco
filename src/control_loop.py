import time
import threading
import numpy as np
import mujoco
from mujoco_interface import MujocoSim
from UDP_interface import udp_receive, udp_send
from main_logic import StewartController
import stewart_ik
# from inverse_kinematics.stewart_ik import get_stewart_ik

# UDP配置
UDP_LOCAL_IP = '172.27.200.139'
UDP_LOCAL_PORT = 3000
UDP_TARGET_IP = '172.27.192.1'
UDP_TARGET_PORT = 3001

# Mujoco配置
XML_PATH = 'stewart.xml'

# 全局变量
controller = StewartController()
sim = MujocoSim(XML_PATH)

def udp_receive_thread():
    """
    UDP接收线程，持续监听UDP数据并发送给控制逻辑处理。
    """
    while True:
        received_data = udp_receive(UDP_LOCAL_IP, UDP_LOCAL_PORT, UDP_TARGET_IP, UDP_TARGET_PORT)
        if received_data:
            controller.process_command(received_data)

def main_control_loop():
    """
    主控制循环，负责控制逻辑、逆运动学、Mujoco仿真以及UDP反馈。
    """
    global controller, sim
    start = time.time()
    with mujoco.viewer.launch_passive(sim.m, sim.d) as viewer:
        while True:
            step_start = time.time()

            # 1. 控制逻辑处理
            target_pose = controller.step_interpolation()
            if target_pose:
                # 2. 逆运动学计算
                target_pose_np = np.array(target_pose)
                target_leg_lengths = stewart_ik.config_arm(target_pose_np)

                target_leg_lengths[0]=(target_leg_lengths[0]-351.8245358903903)/1000
                target_leg_lengths[1]=(target_leg_lengths[1]-353.2537476348852)/1000
                target_leg_lengths[2]=(target_leg_lengths[2]-353.17962646484375)/1000
                target_leg_lengths[3]=(target_leg_lengths[3]-352.8763122558594)/1000
                target_leg_lengths[4]=(target_leg_lengths[4]-352.6863098144531)/1000
                target_leg_lengths[5]=(target_leg_lengths[5]-353.7471923828125)/1000
                print(f"Adjusted target leg lengths: {target_leg_lengths}");


                # 3. Mujoco仿真控制
                sim.apply_leg_lengths(target_leg_lengths)
                mujoco.mj_step(sim.m, sim.d)
                actual_leg_lengths = sim.get_actual_leg_lengths()
                actual_leg_lengths[0]=actual_leg_lengths[0]*1000+351.8245358903903
                actual_leg_lengths[1]=actual_leg_lengths[1]*1000+353.2537476348852
                actual_leg_lengths[2]=actual_leg_lengths[2]*1000+353.17962646484375 
                actual_leg_lengths[3]=actual_leg_lengths[3]*1000+352.8763122558594
                actual_leg_lengths[4]=actual_leg_lengths[4]*1000+352.6863098144531
                actual_leg_lengths[5]=actual_leg_lengths[5]*1000+353.7471923828125
                controller.update_leg_lengths(actual_leg_lengths)
            else:
                # 平台静止时也需要mj_step，否则mujoco会停止
                mujoco.mj_step(sim.m, sim.d)
                actual_leg_lengths = sim.get_actual_leg_lengths()
                actual_leg_lengths[0]=actual_leg_lengths[0]*1000+351.8245358903903
                actual_leg_lengths[1]=actual_leg_lengths[1]*1000+353.2537476348852
                actual_leg_lengths[2]=actual_leg_lengths[2]*1000+353.17962646484375 
                actual_leg_lengths[3]=actual_leg_lengths[3]*1000+352.8763122558594
                actual_leg_lengths[4]=actual_leg_lengths[4]*1000+352.6863098144531
                actual_leg_lengths[5]=actual_leg_lengths[5]*1000+353.7471923828125
                controller.update_leg_lengths(actual_leg_lengths)

            # 4. UDP反馈
            feedback_data = controller.get_feedback()
            udp_send(UDP_TARGET_IP, UDP_TARGET_PORT, feedback_data)

            with viewer.lock():
                viewer.opt.flags[mujoco.mjtVisFlag.mjVIS_CONTACTPOINT] = int(sim.d.time % 2)
            viewer.sync()

            time_until_next_step = sim.m.opt.timestep - (time.time() - step_start)
            if time_until_next_step > 0:
                time.sleep(time_until_next_step)

if __name__ == "__main__":
    # 启动UDP接收线程
    udp_thread = threading.Thread(target=udp_receive_thread)
    udp_thread.daemon = True  # 设置为守护线程，主线程退出时自动结束
    udp_thread.start()
    main_control_loop()

    # 启动主控制循