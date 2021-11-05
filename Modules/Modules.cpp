#include "Modules.h"

#include <iostream>

Modules::Modules() {
    this->modulename = std::string("Undefined");
    std::cout << "Modules base class init" << std::endl;
}

std::string Modules::Version() {
    return std::string("Undefined");
}