#include <iostream>
#include "Core/ATS.h"
#include "Logging/logger.h"

int main()
{
    init_logging(boost::log::trivial::info);
    try
    {
        ATS obj;
        while (1)
            ;
    }catch(std::exception &e)
    {
        std::cout << "Terminating because " << e.what() << std::endl;
    }
    return 0;
}