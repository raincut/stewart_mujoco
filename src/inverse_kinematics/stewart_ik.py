import stewart_ik

'''
q_d: 必须是numpy类型
'''

def get_stewart_ik(q_d):
    return stewart_ik.config_arm(q_d)