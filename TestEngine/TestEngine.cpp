#include "TestEngine.h"

#include "../Utility/Utility.h"

using std::filesystem::current_path;

TestEngine::TestEngine(std::shared_ptr<TestModule> ptr) : Modules()
{
    this->modulename = std::string("TestEngine");
    this->m_testmodule = ptr;

    RegisterTestplans();
}
/**
 * Gets testplan location from m_testplans
 * @param key name of the testplan
 * @param res the result will be placed there
 * @return true if found false if not
 */
bool TestEngine::GetTestplanLocation(std::string key, std::string &res)
{
    {
        std::lock_guard<std::mutex> lk(m_tmtx);
        for (auto &t : this->m_testplans)
        {
            if (t.find(key) != std::string::npos)
            {
                res = t;
                return true;
            }
        }
        return false;
    }
}

void TestEngine::TestEngineLoop()
{
    while (1)
    {
        std::string next_test = GetFromQueue();
        std::string testplan_loc;
        if (!next_test.empty() && GetTestplanLocation(next_test, testplan_loc))
        {
            //Get all tests ready from testplan
            Testplan cur_testplan(testplan_loc);

            std::vector<TestItem> tests = cur_testplan.GetTests();
            std::list<std::string> mods = cur_testplan.GetModules();
            std::map<std::string, void *> test_funcs;
            for (std::string &m : mods)
            {
                //Load module get tests
                std::map<std::string, void *> temp = m_testmodule->GetTestsFromModule(m);
                if (!temp.empty())
                {
                    // Finds all tests from modules
                    for (auto &t : tests)
                    {
                        for (auto const &[key, val] : temp)
                        {
                            if (key == t.GetName())
                            {
                                test_funcs[key] = val;
                            }
                        }
                    }
                }
                else
                {
                    //Fail test because the module for this plan could not be found
                }
            }

            Results res(next_test);
            for (auto &t : tests)
            {
                std::function<TestResult(std::vector<TestParameter>)> fn = GetStdFunction<TestResult(std::vector<TestParameter>)>(test_funcs[t.GetName()]);
                res.AddTestResult(t.GetName(), fn(t.GetParameters()));
            }

            res.WriteFile();
        }
    }
}

/**
 * Registers all available testplans from testplan directory
 */

void TestEngine::RegisterTestplans()
{
    std::string path = std::string(current_path()) + std::string(TESTPLANS_DIR);
    for (const auto &entry : std::filesystem::directory_iterator(path))
    {
        if (entry.path().string().find(".json") != std::string::npos)
        {
            this->m_testplans.push_back(entry.path().string());
        }
    }
}

/**
 * Adds testplan run to queue
 * @param queue name of the module that is being loaded in.
 * @return true if added to queue
 */

bool TestEngine::AddToQueue(std::string name)
{
    {
        std::lock_guard<std::mutex> lk(m_mtx);
        this->m_test_queue.push(name);
    }
}
/**
 * Adds testplan to available testplan list
 * @param location location of the testplan to be added.
 */

void TestEngine::AddTestplan(std::string location)
{
    {
        std::lock_guard<std::mutex> lk(m_tmtx);
        this->m_testplans.push_back(location);
    }
}

/**
 * Pops the next standing test from queue
 * @return returns next test to be run
 */
std::string TestEngine::GetFromQueue()
{
    {
        std::lock_guard<std::mutex> lk(m_mtx);
        if (!m_test_queue.empty())
        {
            std::string test = this->m_test_queue.front();
            this->m_test_queue.pop();
            return test;
        }
        return std::string("");
    }
}
/**
 * Removes testplan from registered testplans
 * @param name name of the testplan to be removed
 */
void TestEngine::RemoveTestplan(std::string name)
{
    {
        std::lock_guard<std::mutex> lk(m_tmtx);
        for (auto &t : this->m_testplans)
        {
            if (t.find(name) != std::string::npos)
            {
                this->m_testplans.remove(t);
                return; //if its the only element it will crash if you dont return
            }
        }
    }
}

std::list<std::string> TestEngine::GetTestPlans()
{
    return m_testplans;
}