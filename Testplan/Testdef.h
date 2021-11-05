#ifndef TESTDEF_H
#define TESTDEF_H

#include <string>

typedef enum 
{
    TEST_SUCESS = 0x0,
    TEST_FAIL,
    TEST_SKIPPED
} TestResult;

enum TypeTag
{
    NoType,
    StringType,
    IntType,
    DoubleType
};
union Value
{
    char* str;
    int i;
    double d;
};
class TestParameter
{
public:
    TestParameter(TypeTag t, Value val) : m_type(t), m_value(val) {

    }
private:
    enum TypeTag m_type;
    union Value m_value;
};

#endif