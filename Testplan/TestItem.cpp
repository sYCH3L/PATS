#include "TestItem.h"

TestItem::TestItem(std::string name, int parametercount)
{
}
bool TestItem::AddParameters(TestParameter par)
{
    m_parameters.push_back(par);
    return true;
}
std::vector<TestParameter> TestItem::GetParameters()
{
    return m_parameters;
}
std::string TestItem::GetName()
{
    return m_name;
}

void TestItem::SetName(std::string name)
{
    m_name = name;
}

void TestItem::SetParameters(std::vector<TestParameter> par)
{
    m_parameters = par;
}

TestItem DeserializeTestItem(const rapidjson::Value &obj)
{
    TestItem res;
    res.SetName(obj["name"].GetString());
    std::vector<TestParameter> par;
    auto array = obj["parameters"].GetArray();
    for (rapidjson::Value::ConstValueIterator itr = array.Begin(); itr != array.End(); ++itr)
    {
        par.push_back(DeserializeTestparameter((*itr)));
    }

    res.SetParameters(par);

    return res;
}
