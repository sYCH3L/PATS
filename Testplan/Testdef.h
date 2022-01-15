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
    bool operator=(int t)
    {
        i = t;
        return true;
    }
    bool operator=(double t)
    {
        d = t;
        return true;
    }
    bool operator=(const char* s)
    {
        *str = *s;
        return true;
    }
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

    Value GetValue() { return m_value; }

    void SetTypeTag(TypeTag t)
    {
        m_type = t;
    }

    void SetValue(int v)
    {
        m_value = (int)v;
    }
    void SetValue(const char* v)
    {
        m_value = (const char*)v;
    }
    void SetValue(double v)
    {
        m_value = (double)v;
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
            writer.String(m_value.str, static_cast<std::string::size_type>(strlen((const char*)m_value.str)));
            break;
        }
        case IntType:
        {
            writer.Int(m_value.i);
            break;
        }
        case DoubleType:
        {
            writer.Double(m_value.d);
            break;
        }
        }
        writer.EndObject();
    }

private:
    TypeTag m_type;
    Value m_value;
};

static TestParameter DeserializeTestparameter(const rapidjson::Value &obj)
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