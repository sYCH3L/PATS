#ifndef TESTPLAN_H
#define TESTPLAN_H

#include "TestItem.h"

#include <list>

#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/prettywriter.h>

class Testplan
{
public:
    Testplan();
    Testplan(std::string location);
    std::vector<TestItem> GetTests();
    std::list<std::string> GetModules();
    std::string ToJson();
    bool FromJson(std::string data);
    std::string GetName();
    void SetTests(std::vector<TestItem> tsts);
    void SetModules(std::list<std::string> mdls);
    bool WriteFile();

    template <typename Writer>
	void Serialize(Writer &writer) const
    {
        writer.StartObject();
        writer.String("name");
        writer.String(m_name.c_str(), static_cast<std::string::size_type>(m_name.length()));
        writer.String("tests");
        writer.StartArray();
        for(auto &e : m_tests)
        {
            e.Serialize(writer);
        }
        writer.EndArray();
        writer.String("modules");
        writer.StartArray();
        for(auto &str : m_modules)
        {
            writer.String(str.c_str(), static_cast<std::string::size_type>(str.length()));
        }
        writer.EndArray();
        writer.EndObject();
    }

private:
    std::string m_name;
    std::vector<TestItem> m_tests;
    std::list<std::string> m_modules;
};

#endif