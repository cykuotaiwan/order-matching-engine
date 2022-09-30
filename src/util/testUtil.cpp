#include <iostream>
#include "testUtil.h"
#include "color.h"

namespace Util
{
    using std::cout;
    using std::endl;

    void printTestMessage(string message)
    {
        cout << YELLOW << message << RESET << endl;
    }
    void printPassMessage(string message)
    {
        cout << GREEN << "\tPass: " << message << RESET << endl;
    }
    void printFailMessage(string message)
    {
        cout << RED << "\tFail: " << message << RESET << endl;
    }
} // namespace Util
