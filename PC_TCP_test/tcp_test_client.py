# -*- coding: UTF-8 -*-
# 导入socket库
import socket

# 建立一个socket连接
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(('127.0.0.1', 9999))
# 打印欢迎信息
print(s.recv(1024).decode('utf-8'))
#发送数据
for data in [b'Michael', b'Tracy', b'Bob']:
    s.send(data)
    print(s.recv(1024).decode('utf-8'))
#退出
s.send('exit')
s.close()