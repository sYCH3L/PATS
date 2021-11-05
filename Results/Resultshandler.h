#ifndef RESULTSHANDLER_H
#define RESULTSHANDLER_H

#include "../Testplan/Testdef.h"

#include <map>
#include <string>
#include <ctime>

class Results 
{
public:
    Results(std::string name);
    bool AddTestResult(std::string name, TestResult res);
    std::string ToJson();
private:
    std::time_t m_starttime;
    std::string m_test_name;
    std::map<std::string, TestResult> m_tests;
};


#endif