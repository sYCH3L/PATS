#ifndef MODULES_H
#define MODULES_H

#include <string>

class Modules
{
public:
    Modules();
    virtual std::string Version();
    std::string modulename;
};

#endif