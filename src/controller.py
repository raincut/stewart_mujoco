import time

import mujoco
import mujoco.viewer

m = mujoco.MjModel.from_xml_path('stewart.xml')
d = mujoco.MjData(m)

# L_t=[351.8244,353.2537,353.1796,352.8763,352.6863,353.7472]/1000

with mujoco.viewer.launch_passive(m, d) as viewer:
    start = time.time()
    while viewer.is_running():
        step_start = time.time()
        d.ctrl=[0.19,0.19,0.19,0.15,0.19,0.19]
        mujoco.mj_step(m, d)
        with viewer.lock():
            viewer.opt.flags[mujoco.mjtVisFlag.mjVIS_CONTACTPOINT] = int(d.time % 2)
        viewer.sync()
        time_until_next_step = m.opt.timestep - (time.time() - step_start)
        if time_until_next_step > 0:
            time.sleep(time_until_next_step)