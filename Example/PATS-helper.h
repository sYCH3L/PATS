#ifndef PATS_HELPER_H
#define PATS_HELPER_H

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
    }

private:
    TypeTag m_type;
    Value m_value;
};

#endif