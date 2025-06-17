#!/usr/bin/env python3

import rclpy
import csv
import os
from rclpy.node import Node
from sensor_msgs.msg import JointState
from datetime import datetime

"""
1.记录数据✅
2.向上位机发送数据（待定）
3.向可视化界面发送数据（待定）
"""

class JointStateLogger(Node):
    def __init__(self):
        super().__init__('joint_state_logger')
        
        # 创建日志文件
        self.log_dir = "joint_logs"
        os.makedirs(self.log_dir, exist_ok=True)
        timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
        self.filename = os.path.join(self.log_dir, f"joint_log_{timestamp}.csv")
        
        # 初始化CSG写入器
        self.csv_file = open(self.filename, 'w', newline='')
        self.writer = csv.writer(self.csv_file)
        header = ['timestamp']
        for j in ['s1', 's2', 's3', 's4', 's5', 's6']:
            header += [f'{j}_position', f'{j}_velocity']
        self.writer.writerow(header)
        
        # 创建订阅者
        self.subscription = self.create_subscription(
            JointState,
            '/joint_states',
            self.joint_state_callback,
            10)
        
        self.get_logger().info(f"Joint state logger initialized. Saving to {self.filename}")

    def joint_state_callback(self, msg):
        # 创建数据字典
        data = {'timestamp': msg.header.stamp.sec + msg.header.stamp.nanosec * 1e-9}
        
        # 按顺序收集所有关节数据
        for name in ['s1', 's2', 's3', 's4', 's5', 's6']:
            if name in msg.name:
                idx = msg.name.index(name)
                data[f'{name}_position'] = msg.position[idx]
                data[f'{name}_velocity'] = msg.velocity[idx] if len(msg.velocity) > idx else 0.0
            else:
                data[f'{name}_position'] = 0.0
                data[f'{name}_velocity'] = 0.0
        
        # 按列顺序写入数据
        row = [data['timestamp']]
        for j in ['s1', 's2', 's3', 's4', 's5', 's6']:
            row += [f"{data[f'{j}_position']:.6f}", 
                    f"{data[f'{j}_velocity']:.6f}"]
        
        self.writer.writerow(row)
    def destroy_node(self):
        # 关闭文件
        self.csv_file.close()
        self.get_logger().info(f"Log file saved to {self.filename}")
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    logger = JointStateLogger()
    try:
        rclpy.spin(logger)
    except KeyboardInterrupt:
        pass
    finally:
        logger.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()