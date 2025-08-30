#include "my_class.h"

MyClass::MyClass(/* args */)
{
}

MyClass::MyClass(int data) : data(data)
{
}

MyClass::~MyClass()
{
}

void MyClass::Add()
{
    data += magnifier;
}

void MyClass::SetMagnifier(int magnifier)
{
    this->magnifier = magnifier;
}

int MyClass::GetData() const noexcept
{
    return data;
}

int MyClass::GetMagnifier() const noexcept
{
    return magnifier;
}