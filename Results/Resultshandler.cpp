#include "Resultshandler.h"

Results::Results(std::string name) : m_test_name(name)
{
    this->m_starttime = std::time(nullptr);
}
/**
 * Adds testresult
 *
 * This sum is the arithmetic sum, not some other kind of sum that only
 * mathematicians have heard of.
 *
 * @param name name of test
 * @param res result of test
 * @return true success, false failure
 */

bool Results::AddTestResult(std::string name, TestResult res)
{
    const auto [it, success] = m_tests.insert(std::pair{name, res});
    return success;
}


/**
 * Converts results to json
 *
 * Converts testplan results to json result
 */

std::string Results::ToJson()
{

}