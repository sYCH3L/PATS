#include "Testplan.h"

#include "../Utility/Config_location.h"

#include <fstream>

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
std::string Testplan::GetName()
{
    return m_name;
}

std::string Testplan::ToJson()
{
	rapidjson::StringBuffer sb;
	rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(sb);

    writer.StartObject();
    this->Serialize(writer);
    writer.EndObject();

    return sb.GetString();
}
std::string Testplan::FromJson()
{
    
}

bool Testplan::WriteFile()
{
    std::string data = this->ToJson();
    std::string path = TESTPLANS_DIR + m_name + ".json";

    std::ofstream output(path);

    if(!output.is_open())
    {
        return false;
    }

    output << data;

    output.close();

    return true;
}