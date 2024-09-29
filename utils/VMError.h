#ifndef VMERROR_H
#define VMERROR_H
#include <ctime>
#include <cstring>
#include <cerrno>
#include <cerrno>   // for errno
#include <iostream>
#include <iostream>

class VMError{
public:
    //打印错误
    static void vm_error(const std::string& msg){
        time_t now = time(0);
        char* dt = ctime(&now);
        dt[strlen(dt) - 1] = '\0';
         std::cerr << "[" << dt << "] Error: " << msg 
                  << ". Errno: " << errno << " (" << strerror(errno) << ")" 
                  << std::endl;
    }
};
#endif