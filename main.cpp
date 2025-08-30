#include <iostream>
#include "my_class.h"

using namespace std;

int main()
{
    MyClass myClass(6);

    std::cout << myClass.GetData() << "\n";

    myClass.Add();
    std::cout << myClass.GetData() << "\n";

    return 0;
}
