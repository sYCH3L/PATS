#ifndef TESTDEF_H
#define TESTDEF_H

#include <string>

#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/prettywriter.h>

typedef enum
{
    TEST_SUCESS = 0x0,
    TEST_FAIL,
    TEST_SKIPPED
} TestResult;

typedef enum
{
    NoType,
    StringType,
    IntType,
    DoubleType
} TypeTag;
typedef union
{
    char *str;
    int i;
    double d;
} Value;
class TestParameter
{
public:
    TestParameter()
    {

    }
    TestParameter(TypeTag t, Value val) : m_type(t), m_value(val)
    {
    }

    void SetTypeTag(TypeTag t)
    {
        m_type = t;
    }

    template<class T>
    void SetValue(T v)
    {
        m_value = (T)v;
    }

    template <typename Writer>
    void Serialize(Writer &writer) const
    {
        writer.StartObject();
        writer.String("type");
        writer.Int(m_type);
        writer.String("value");

        switch (m_type)
        {
        case StringType:
        {
            writer.String(m_value.c_str(), static_cast<std::string::size_type>(m_value.length()));
            break;
        }
        case IntType:
        {
            writer.int(m_value);
            break;
        }
        case DoubleType:
        {
            writer.Double(m_value);
            break;
        }
        }
        writer.EndObject();
    }

private:
    TypeTag m_type;
    Value m_value;
};

TestParameter DeserializeTestparameter(const rapidjson::Value &obj)
{
    TestParameter par;
    TypeTag tmp = (TypeTag)obj["type"].GetInt();
    par.SetTypeTag(tmp);

    switch (tmp)
    {
    case StringType:
    {
        par.SetValue(obj["value"].GetString());
    }
    case IntType:
    {
        par.SetValue(obj["value"].GetInt());
        break;
    }
    case DoubleType:
    {
        par.SetValue(obj["value"].GetInt());
        break;
    }
    }

    return par;
}

#endif