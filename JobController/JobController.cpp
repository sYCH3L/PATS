#include "JobController.h"
#include "../Utility/Utility.h"

JobController::JobController(std::shared_ptr<TestEngine> ptr) : Modules()
{
    this->modulename = std::string("Jobcontroller");
    this->m_testengine = ptr;
}

void JobController::DeleteTestplan(std::string name)
{

    std::list<std::string> testplans = m_testengine.get()->GetTestPlans();
    for (auto &str : testplans)
    {
        if (str.find(name) != std::string::npos)
        {
            std::cout << "Found testplan removing from filesystem" << std::endl;
            if (std::filesystem::exists(str))
            {
                std::filesystem::remove(str);
            }
            std::cout << "Removing from list" << std::endl;
            m_testengine.get()->RemoveTestplan(name);
        }
    }
}

bool JobController::CheckIfTestplanExists(std::string name)
{
    std::list<std::string> testplans = m_testengine.get()->GetTestPlans();
    for (auto &str : testplans)
    {
        if (str.find(name) != std::string::npos)
        {
            return true;
        }
    }
    return false;
}

bool JobController::AddTestPlan(std::string name, std::string data)
{
    Testplan tmp;
    if (tmp.FromJson(data))
    {
        bool res = tmp.WriteFile();
        std::string loc = std::filesystem::current_path().string() + TESTPLANS_DIR + name + ".json";
        m_testengine.get()->AddTestplan(loc);
        return res;
    }

    return false;
}
void JobController::RunTestplan(std::string name)
{
    m_testengine.get()->AddToQueue(name);
}
std::list<std::string> JobController::GetAllTestplanNames()
{
    std::list<std::string> testplans = m_testengine.get()->GetTestPlans();
    std::list<std::string> res;

    for (auto &str : testplans)
    {
        std::string tmp = split(split(str, "/").back(), ".").front();
        res.push_back(tmp);
    }

    return res;
}
std::string JobController::GetTestplan(std::string name)
{
    std::list<std::string> testplans = m_testengine.get()->GetTestPlans();

    for (auto &str : testplans)
    {
        if (str.find(name) != std::string::npos)
        {
            std::cout << "Converting to json" << std::endl;
            return Testplan(str).ToJson();
        }
    }
}