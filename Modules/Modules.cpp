#include "Modules.h"

#include <iostream>

Modules::Modules() {
    this->modulename = std::string("Undefined");
}

std::string Modules::Version() {
    return std::string("Undefined");
}