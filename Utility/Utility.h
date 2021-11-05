#ifndef UTILITY_H
#define UTILITY_H
/*
    Utility file
    Holds utility structures and functions
*/
#include <iostream>
#include <functional>

typedef enum
{
    IPV4 = 0x0,
    IPV6 = 0x1
} Addr_Config;

static void WriteGenericLog(std::string module, std::string msg)
{
    std::cout << "[" << module << "]"
              << " " << msg << std::endl;
}

template <class T>
static std::function<T> GetStdFunction(void* ptr)
{
    return reinterpret_cast<T*>(ptr);
}

#endif