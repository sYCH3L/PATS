#include <iostream>
#include "Core/ATS.h"
#include "Logging/logger.h"

int main() {
    init_logging(boost::log::trivial::info);
    ATS obj;
    while(1);
}