#ifndef TESTPLAN_H
#define TESTPLAN_H

#include "TestItem.h"

#include <list>

class Testplan
{
public:
    Testplan();
    Testplan(std::string location);
    std::vector<TestItem> GetTests();
    std::list<std::string> GetModules();
    void SetTests(std::vector<TestItem> tsts);
    void SetModules(std::list<std::string> mdls);
private:
    std::vector<TestItem> m_tests;
    std::list<std::string> m_modules;
};

#endif