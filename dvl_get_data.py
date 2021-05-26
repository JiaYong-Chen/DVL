import socket
import time

def main():
    tcp_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # The IP address must be updated every time after power on.
    dest_addr = ('169.254.54.178', 9002) 
    tcp_socket.connect(dest_addr)

    recv_data = tcp_socket.recv(1024)
    print('Received data: ')
    print(recv_data)
    print(len(recv_data))

    while True:    
        # Delete the Chinese comment before the test, otherwise an error will be reported.
        # 将recv的参数设为1024，同时把时间延迟删掉，再加上print(len(recv_data))可以知道每个数据包的长度
        recv_data = tcp_socket.recv(222)
        time.sleep(1)
        if not recv_data:
            break
        # 接收到的数据格式为str，需要将其转换一下格式，根据数据包的定义，按字节将需要的数据取出来
        for c in recv_data:
            print(ord(c))  #ord(c)返回字符c对应的十进制数
        print('Received data: ')
        print(recv_data)

    tcp_socket.close()

if __name__ == "__main__":
        main()