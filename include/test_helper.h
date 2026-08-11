#ifndef LEETCODE_TEST_HELPER_H
#define LEETCODE_TEST_HELPER_H

#include <stdexcept>
#include <string>

namespace testHelper {

[[noreturn]] inline void fail(const char* expression, const char* file, int line) {
    throw std::runtime_error(std::string(file) + ':' + std::to_string(line) + ": check failed: " + expression);
}

}  // namespace testHelper

#define CHECK(expression)                                                     \
    do {                                                                      \
        if (!(expression)) testHelper::fail(#expression, __FILE__, __LINE__); \
    } while (false)

#endif  // LEETCODE_TEST_HELPER_H
