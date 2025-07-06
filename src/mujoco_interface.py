import mujoco
import mujoco.viewer
import time

class MujocoSim:
    def __init__(self, xml_path):
        self.m = mujoco.MjModel.from_xml_path(xml_path)
        self.d = mujoco.MjData(self.m)

    def apply_leg_lengths(self, lengths):
        # 假设d.ctrl为六杆长度控制
        self.d.ctrl[:] = lengths
        mujoco.mj_step(self.m, self.d)

    def get_actual_leg_lengths(self):
        # 可根据仿真反馈实际杆长
        # print("Actual leg lengths:", self.d.ctrl[:6])
        return list(self.d.ctrl[:6])

if __name__ == "__main__":
    sim = MujocoSim('stewart.xml')
    start = time.time()
    with mujoco.viewer.launch_passive(sim.m, sim.d) as viewer:
        while True:
            step_start = time.time()
            # sim.apply_leg_lengths([0.05, 0.05, 0.05, 0.05, 0.05, 0.05])
            mujoco.mj_step(sim.m, sim.d)
            with viewer.lock():
                viewer.opt.flags[mujoco.mjtVisFlag.mjVIS_CONTACTPOINT] = int(sim.d.time % 2)
            viewer.sync()
            time_until_next_step = sim.m.opt.timestep - (time.time() - step_start)
            if time_until_next_step > 0:
                time.sleep(time_until_next_step)
