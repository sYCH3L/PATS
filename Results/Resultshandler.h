#ifndef RESULTSHANDLER_H
#define RESULTSHANDLER_H

#include "../Testplan/Testdef.h"

#include <map>
#include <string>
#include <ctime>

#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/prettywriter.h>

class Results 
{
public:
    Results(std::string name);
    bool AddTestResult(std::string name, TestResult res);
    std::string ToJson();
    bool FromJson(std::string data);
    bool WriteFile();

    template <typename Writer>
	void Serialize(Writer &writer) const
    {
        writer.String("Time");
        writer.Int(m_starttime);
        writer.String("name");
        writer.String(m_test_name.c_str(), static_cast<std::string::size_type>(m_test_name.length()));
        writer.String("tests");
        writer.StartArray();
        for (auto const &[k, v] : m_tests)
        {
            writer.StartObject();
            writer.String("name");
            writer.String(k.c_str(), static_cast<std::string::size_type>(k.length()));
            writer.String("result");
            writer.Int(v);
            writer.EndObject();
        }

        
    }
private:
    std::time_t m_starttime;
    std::string m_test_name;
    std::map<std::string, TestResult> m_tests;
};


#endif