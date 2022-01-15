#ifndef TESTENGINE_H
#define TESTENGINE_H

#include <string>
#include <sstream>
#include <queue>
#include <list>
#include <thread>
#include <mutex>
#include <functional>
#include <filesystem>
#include <iostream>

#include "Version.h"

#include "../Testplan/Testplan.h"
#include "../Testplan/Testdef.h"
#include "../Modules/Modules.h"
#include "../Utility/Config_location.h"
#include "../Utility/Utility.h"
#include "../TestModule/TestModule.h"
#include "../Results/Resultshandler.h"

class TestEngine : public Modules
{
public:
    explicit TestEngine(std::shared_ptr<TestModule> ptr);
    std::string Version()
    {
        std::ostringstream verstr;
        verstr << TESTENGINE_MAJOR << "." << TESTENGINE_MINOR << "." << TESTENGINE_PATCH;
        return verstr.str();
    }
    void AddTestplan(std::string location);
    void RemoveTestplan(std::string name);
    bool AddToQueue(std::string name);

    std::list<std::string> GetTestPlans();

private:
    void RegisterTestplans();
    void TestEngineLoop();
    std::string GetFromQueue();

    bool GetTestplanLocation(std::string key, std::string &res);

    std::list<std::string> m_testplans;
    std::queue<std::string> m_test_queue;
    std::shared_ptr<TestModule> m_testmodule;
    std::mutex m_mtx;
    std::mutex m_tmtx;
};

#endif