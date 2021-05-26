#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include "data_format.h"
#define bufsize 1024 //定义每次接收的数据的长度-

int main()
{
	int client_sockfd; //客户端套接字描述符
	int len;
	struct sockaddr_in remote_addr; //服务器端网络地址结构体
	char buf[bufsize];  //数据传送的缓冲区
	memset(&remote_addr,0,sizeof(remote_addr)); //数据初始化--清零
	remote_addr.sin_family = AF_INET; //设置为IP通信
	remote_addr.sin_addr.s_addr = inet_addr("169.254.223.174");//服务器IP地址
	remote_addr.sin_port = htons(9002); //服务器端口号
	
	/*创建客户端套接字--IPv4协议，面向连接通信，TCP协议，socket创建失败则返回-1*/
	if((client_sockfd = socket(PF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("socket error");
		return 1;
	}
	
	/*将套接字绑定到服务器的网络地址上，connetion失败则返回-1*/
	if(connect(client_sockfd, (struct sockaddr *)& remote_addr, sizeof(struct sockaddr)) < 0)
	{
		perror("connect error");
		return 1;
	}
    printf("connected to server\n");

    /*接受DVL发送的开头信息，recv返回接收到的字节数*/
	len = recv(client_sockfd, buf, bufsize, 0);//接收服务器端信息
    buf[len] = '\0';
    printf("len: %d\n", len);
	printf("The head of DVL: %s", buf); //打印服务器端信息
	
	/*循环接收信息并打印接收信息*/
	while(1)
	{
		len = recv(client_sockfd, buf, bufsize, 0);
		buf[len] = '\0';
        printf("len: %d\n", len);
		printf("Received data: %s\n", buf);
	}
	
	/*关闭套接字*/
	close(client_sockfd);
    
	return 0;
}