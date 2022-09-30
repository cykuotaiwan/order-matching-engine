#ifndef TEST_UTIL_H
#define TEST_UTIL_H

#include <string>

namespace Util
{
    using std::string;

    void printTestMessage(string message);
    void printPassMessage(string message);
    void printFailMessage(string message);
} // namespace Util

#endif