#ifndef JOBCONTROLLER_H
#define JOBCONTROLLER_H

#include <string>
#include <sstream>
#include <memory>


#include "Version.h"
#include "../Modules/Modules.h"
#include "../TestEngine/TestEngine.h"

class JobController : public Modules
{
public:
    explicit JobController(std::shared_ptr<TestEngine> ptr);
    std::string Version() 
    {
        std::ostringstream verstr;
        verstr << JOBCONTROLLER_MAJOR << "." << JOBCONTROLLER_MINOR << "." << JOBCONTROLLER_PATCH;
        return verstr.str();
    }

    void DeleteTestplan(std::string name);
    bool AddTestPlan(std::string name, std::string data);
    void RunTestplan(std::string name);

    std::list<std::string> GetAllTestplanNames();
    bool CheckIfTestplanExists(std::string name);
    std::string GetTestplan(std::string name);
private:
    std::shared_ptr<TestEngine> m_testengine;
};

#endif