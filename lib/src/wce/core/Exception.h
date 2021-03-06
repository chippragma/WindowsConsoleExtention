#pragma once

#include <exception>
#include <string>

namespace wce {

class Exception : public std::exception {
public:
    explicit Exception(const std::string &message);

    const char *what() const noexcept override;

protected:
    std::string mMessage;
};

}




