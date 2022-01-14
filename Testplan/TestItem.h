#ifndef TESTITEM_H
#define TESTITEM_H

#include "Testdef.h"

#include <vector>
#include <string>

#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/prettywriter.h>

class TestItem
{
public:
    TestItem()
    {
        
    }
    TestItem(std::string name, int parametercount);
    bool AddParameters(TestParameter par);
    std::vector<TestParameter> GetParameters();
    std::string GetName();
    void SetName(std::string name);
    void SetParameters(std::vector<TestParameter> par);

    template <typename Writer>
	void Serialize(Writer &writer) const
    {
        writer.StartObject();
        writer.String("name");
        writer.String(m_name.c_str(), static_cast<std::string::size_type>(m_name.length()));
        writer.String("parameters");
        writer.StartArray();
        for(auto &e : m_parameters)
        {
            e.Serialize(writer);
        }
        writer.EndArray();
        writer.EndObject();
    }

private:
    std::string m_name;
    std::vector<TestParameter> m_parameters;
};

TestItem DeserializeTestItem(const rapidjson::Value &obj);

#endif