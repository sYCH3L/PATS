#ifndef TESTITEM_H
#define TESTITEM_H

#include "Testdef.h"

#include <vector>
#include <string>

class TestItem
{
public:
    TestItem(std::string name, int parametercount);
    bool AddParameters(TestParameter par);
    std::vector<TestParameter> GetParameters();
    std::string GetName();
private:
    std::string m_name;
    std::vector<TestParameter> parameters;
};

#endif