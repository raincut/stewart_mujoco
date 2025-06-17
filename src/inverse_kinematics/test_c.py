import stewart_ik
import numpy as np

qd=np.array([0.0, 0.0, 0.0, 0.0, 0.0, 0.0])
print(stewart_ik.config_arm(qd))