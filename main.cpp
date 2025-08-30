#include <iostream>
#include "my_class.h"

using namespace std;

/**
 * @brief      Start program
 *
 * @details    Call int main
 *
 * @todo Example Todo
 * @warning This is a test
 * @see Ref
 *
 * @return     Succer implement.
 */

int main()
{
    MyClass myClass(6);

    std::cout << myClass.GetData() << "\n";

    myClass.Add();
    std::cout << myClass.GetData() << "\n";

    return 0;
}
