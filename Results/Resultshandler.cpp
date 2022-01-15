#include "Resultshandler.h"
#include "../Utility/Config_location.h"

#include <fstream>
#include <filesystem>

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
    rapidjson::StringBuffer sb;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(sb);

    writer.StartObject();
    this->Serialize(writer);
    writer.EndObject();

    return sb.GetString();
}
/**
 * Converts to result from json
 * @param data - json data
 * @return true if successful false if not
 */

bool Results::FromJson(std::string data)
{
    //TODO: Implement
    return false;
}

/**
 * Writes result into json data
 * @return true if successful false if not
 */

bool Results::WriteFile()
{
    std::string data = this->ToJson();
    std::string path = std::filesystem::current_path().string() + RESULTS_DIR + m_test_name + "_" + std::to_string(m_starttime) + ".json";

    std::ofstream output(path);

    if (!output.is_open())
    {
        return false;
    }

    output << data;

    output.close();

    return true;
}