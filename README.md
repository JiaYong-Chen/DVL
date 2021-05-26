# DVL
DVL data reading
1. 关于文件夹 PC_TCP_test:
    这只是在同一台电脑上开启两个进程（客户进程和服务器进程）进行TCP通信测试，可用于第一次接触TCP时的学习测试。
		
2. 关于文件夹 tcp_test_cpp:
    这是一个用C++编写的TCP进程测试，也是用于同一台电脑上两个进程的通信测试

3. 关于文件 DVL_TCP_Client:
    真正用于DVL读取数据的程序，C++版本。最好还是用这一个，因为DVL发送的数据格式用C++接收比较合适，python提供的数据类型比较少
    其中 data_format.cpp 定义了DVL发送回来的数据的结构
    具体数据格式见 N3015-008 Nortek DVL Integrators Guide1018.pdf

4. dvl_get_data.py:
    也是用于DVL读取数据的程序，python版本
