#ifndef SOCKET_H
#define SOCKET_H
#include <sys/socket.h>
#include <cerrno>
#include <iostream>
#include <memory>
#include <unistd.h>
#include "VMError.h"

class _Socket;

class VMSocket{
public:
    void Close(){
        m_socket.reset();
    }

public:
    VMSocket(bool isTcp = true):
        m_socket(std::make_shared<_Socket>(isTcp)),
        m_isTcp(isTcp){
    }
    VMSocket(const VMSocket& s):
        m_socket(s.m_socket),
        m_isTcp(s.m_isTcp){
    }
    VMSocket(int sockfd,bool isTcp){
        m_socket = std::make_shared<_Socket>(sockfd,isTcp);
        m_isTcp = isTcp;
    }
    ~VMSocket(){
       m_socket.reset();
    }
    // operator _Socket(){
    //     return *m_socket;
    // }
    
private:
    std::shared_ptr<_Socket> m_socket; // share ptr指针，用于_Socket间的互相引用，避免出现多份
    bool m_isTcp;
};

class _Socket
{
public:
    //bIsTcp 表示底层使用tcp还是udp
    _Socket(bool isTcp=true){
        m_socket_serverfd = -1;
        if(isTcp){
            m_socket_serverfd = socket(AF_INET,SOCK_STREAM,0);
        }else{
            m_socket_serverfd = socket(AF_INET,SOCK_DGRAM,0);
        }
         if(!m_socket_serverfd){
            VMError::vm_error("init server socket!");
            return;
        }

    }
    //有参构造
    _Socket(int socket_fd,bool isTcp=true){
        m_socket_serverfd = socket_fd;
    }
    //关闭socket fd
    void Close(){
        if(m_socket_serverfd != -1){
            int tmp = m_socket_serverfd;
            close(tmp);
            m_socket_serverfd = -1;
        }
    }
    //类型转换运算符重构
    // operator _Socket(){
    //     return m_socket_serverfd;
    // }
private:

private:
    int m_socket_serverfd;//服务端socket fd
};



#endif //SOCKET_H