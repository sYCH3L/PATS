#include <stdio.h>
#include "lib/include/wiringPi.h"
#include "../PATS-helper.h"

#include <map>
#include <string>
#include <vector>

static TestResult demo_test_function(std::vector<TestParameter> parameters)
{
    return TEST_SUCESS;
}


std::map<std::string, void*> init()
{
    std::map<std::string, void*> res {
        {std::string("demo_test_function"), (void*)&demo_test_function}
    };

    return res;
}