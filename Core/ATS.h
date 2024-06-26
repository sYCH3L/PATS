#ifndef ATS_H
#define ATS_H

#include "../Backend/Backend.h"
#include "../JobController/JobController.h"
#include "../TestEngine/TestEngine.h"
#include "../TestModule/TestModule.h"

#include "../Utility/Utility.h"
#include "Version.h"
#include "../Modules/Modules.h"

#include "../Handlers/Modulehandler.h"
#include "../Handlers/Testplanhandler.h"
#include "../Handlers/reshandler.h"
#include "../Handlers/testmoduleshandler.h"

#include <string>
#include <sstream>
#include <memory>

class ATS : public Modules
{
public:
    explicit ATS();
    ~ATS();

    std::string Version()
    {
        std::ostringstream verstr;
        verstr << ATS_MAJOR << "." << ATS_MINOR << "." << ATS_PATCH;
        return verstr.str();
    }

private:
    bool ReadConfigFile();
    void GetDefaultParameters();
    std::string GetConfigFile();
    void InitExtHandlers();

    std::shared_ptr<Modulehandler> m_modulehandler;
    std::shared_ptr<TestModule> m_testmodule;
    std::shared_ptr<TestEngine> m_testengine;
    std::shared_ptr<Backend> m_backend;
    std::shared_ptr<JobController> m_jobcontroller;
    std::shared_ptr<TestplanHandler> m_testplanhndlr;
    std::shared_ptr<ResHandler> m_reshndlr;
    std::shared_ptr<TestModuleHandler> m_testmodhndlr;
};

#endif