#include "Operation.h"

Operation::Operation(const string type) : m_type(type)
{
}

std::string Operation::getName() const
{
    return m_type;
}

void Operation::print(const string& str) const
{
    //print the operation and the string 
    auto opName = getName();
    cout << opName <<"(" << str << ") = ";
}
