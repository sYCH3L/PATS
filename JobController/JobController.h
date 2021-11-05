#ifndef JOBCONTROLLER_H
#define JOBCONTROLLER_H

#include <string>
#include <sstream>

#include "Version.h"
#include "../Modules/Modules.h"

class JobController : public Modules
{
public:
    explicit JobController();
    std::string Version() 
    {
        std::ostringstream verstr;
        verstr << JOBCONTROLLER_MAJOR << "." << JOBCONTROLLER_MINOR << "." << JOBCONTROLLER_PATCH;
        return verstr.str();
    }
private:

};

#endif