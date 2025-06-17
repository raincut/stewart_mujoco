import socket
import struct

# 结构体格式
RECV_STRUCT_FORMAT = ">IIIIffffffI"
RECV_STRUCT_SIZE = struct.calcsize(RECV_STRUCT_FORMAT)
SEND_STRUCT_FORMAT = ">IIffffffffffffI"
SEND_STRUCT_SIZE = struct.calcsize(SEND_STRUCT_FORMAT)

def udp_receive(local_ip, local_port, target_ip, target_port, timeout=0.1):
    """
    阻塞接收UDP数据，返回解包后的数据（去除头尾），仅处理来自目标IP和端口的数据。
    """
    udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    udp_socket.bind((local_ip, local_port))
    udp_socket.settimeout(timeout)
    try:
        while True:
            try:
                data, addr = udp_socket.recvfrom(1024)
                if addr[0] != target_ip or addr[1] != target_port:
                    continue
                if len(data) != RECV_STRUCT_SIZE:
                    print(f"Received data length {len(data)} does not match expected length {RECV_STRUCT_SIZE}, skipping.")
                    continue
                unpacked = struct.unpack(RECV_STRUCT_FORMAT, data)
                print(f"Received data from {addr}: {unpacked}")
                if unpacked[0] == 0x55555555 and unpacked[-1] == 0xaaaaaaaa:
                    unpacked_list = list(unpacked)
                    unpacked_list[4]  # 毫米，用于逆运动学计算
                    unpacked_list[5]
                    unpacked_list[6]
                    unpacked_list[7] /= 180 / 3.1415926
                    unpacked_list[8] /= 180 / 3.1415926
                    unpacked_list[9] /= 180 / 3.1415926
                    print(f"Unpacked data: {unpacked_list[1:-1]}")
                    return unpacked_list[1:-1]  # 去掉头尾          
            except socket.timeout:
                continue
    finally:
        udp_socket.close()

def udp_send(target_ip, target_port, feedback_data):
    """
    发送UDP数据，feedback_data为长度14的列表，包含各项数据。
    """
    # if feedback_data is None or len(feedback_data) < 14:
    #     raise ValueError("feedback_data长度不足14")
    

    head = 0x66666666
    tail = 0x88888888
    udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    try:
        data = struct.pack(
            SEND_STRUCT_FORMAT,
            head,
            int(feedback_data[0]),  # count
            float(feedback_data[1]),  # status
            float(feedback_data[2]),  # x
            float(feedback_data[3]),  # y
            float(feedback_data[4])/3.1415926*180,  # z
            float(feedback_data[5])/3.1415926*180,  # roll
            float(feedback_data[6])/3.1415926*180,  # yaw
            float(feedback_data[7]),  # pitch
            float(feedback_data[8]),  # l1
            float(feedback_data[9]),  # l2
            float(feedback_data[10]), # l3
            float(feedback_data[11]), # l4
            float(feedback_data[12]), # l5
            tail
        )
        udp_socket.sendto(data, (target_ip, target_port))
    finally:
        udp_socket.close()

if __name__ == "__main__":
    udp_local_ip = '172.27.200.139'
    udp_local_port = 3000
    udp_target_ip = '172.27.192.1'
    udp_target_port = 3001
    udp_receive(udp_local_ip, udp_local_port, udp_target_ip, udp_target_port)

    # 55555555 00000004 00000001 00000000 41200000 41200000 41200000 00000000 00000000 00000000 aaaaaaaa
    # 帧头          
    # 66 66 66 66|00 00 00 00|44 7a 00 00|00 00 00 00|46 1c 40 00|44 0f 3d 4d|44 0f 3d 4d|00 00 00 00|00 00 00 00|00 00 00 00|41 2e bf 0e|41 4f 3b 52|40 a4 68 85|41 2d 64 fe|88 88 88 88
    # 66 66 66 66 00 00 00 03 41 20 00 00 41 20 00 00 41 20 00 00 00 00 00 00 00 00 00 00 00 00 00 00 43 b5 5f 83 43 b7 1a 55 43 b3 28 a0 43 b5 db 53 43 b6 ce 51 43 b3 68 a1 88 88 88 88