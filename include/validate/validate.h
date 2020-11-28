#pragma once

#define validate(condition, return_statement, message) \
    if (!(condition)) { \
        std::cerr << message << " (" << __FILE__ << " " << __FUNCTION__ << " " << __LINE__ << ")" << std::endl; \
        return return_statement; \
    }