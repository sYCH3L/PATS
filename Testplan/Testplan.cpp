#include "Testplan.h"

#include "../Utility/Config_location.h"
#include "../Utility/Utility.h"

#include <fstream>
#include <filesystem>

Testplan::Testplan()
{
}
Testplan::Testplan(std::string location)
{
    std::string data = GetDataFromFile(location);
    if (!data.empty())
    {
        std::cout << "Document" << std::endl;
        rapidjson::Document d;
        d.Parse(data.c_str());
        if (d.HasParseError())
        {
            std::cout << "Error parsing testplan" << std::endl;
            return;
        }

        if (d.HasMember("name"))
        {
            m_name = d["name"].GetString();
        }

        if (d.HasMember("tests") && d["tests"].IsArray())
        {
            auto tests = d["tests"].GetArray();
            for (rapidjson::Value::ConstValueIterator itr = tests.Begin(); itr != tests.End(); ++itr)
            {
                m_tests.push_back(DeserializeTestItem(*itr));
            }
        }

        if (d.HasMember("modules") && d["modules"].IsArray())
        {

            auto modules = d["modules"].GetArray();

            for (rapidjson::Value::ConstValueIterator itr = modules.Begin(); itr != modules.End(); ++itr)
            {
                m_modules.push_back((*itr).GetString());
            }
        }
    }
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
std::string Testplan::GetName()
{
    return m_name;
}

std::string Testplan::ToJson()
{
    rapidjson::StringBuffer sb;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(sb);

    this->Serialize(writer);

    return sb.GetString();
}
bool Testplan::FromJson(std::string data)
{
    try
    {
        if (!data.empty())
        {
            rapidjson::Document d;
            d.Parse(data.c_str());
            if (d.HasParseError())
            {
                std::cout << "Error parsing testplan" << std::endl;
                return false;
            }

            if (d.HasMember("name"))
            {
                m_name = d["name"].GetString();
            }

            if (d.HasMember("tests") && d["tests"].IsArray())
            {
                auto tests = d["tests"].GetArray();
                for (rapidjson::Value::ConstValueIterator itr = tests.Begin(); itr != tests.End(); ++itr)
                {
                    m_tests.push_back(DeserializeTestItem(*itr));
                }
            }

            if (d.HasMember("modules") && d["modules"].IsArray())
            {

                auto modules = d["modules"].GetArray();

                for (rapidjson::Value::ConstValueIterator itr = modules.Begin(); itr != modules.End(); ++itr)
                {
                    m_modules.push_back((*itr).GetString());
                }
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }

    return true;
}

bool Testplan::WriteFile()
{
    std::string data = this->ToJson();
    std::string path = std::filesystem::current_path().string() + TESTPLANS_DIR + m_name + ".json";

    std::ofstream output(path);

    if (!output.is_open())
    {
        std::cout << "Cannot open file loc: " << path;
        return false;
    }

    output << data;

    output.close();

    return true;
}