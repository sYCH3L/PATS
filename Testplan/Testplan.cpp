#include "Testplan.h"

Testplan::Testplan()
{
    
}
Testplan::Testplan(std::string location)
{
    std::string buff;
}
void Testplan::SetTests(std::vector<TestItem> tsts)
{
    this->m_tests = tsts;
}
void Testplan::SetModules(std::list<std::string> mdls)
{
    this->m_modules = mdls;
}
std::vector<TestItem> Testplan::GetTests()
{
    return this->m_tests;
}
std::list<std::string> Testplan::GetModules()
{
    return this->m_modules;
}