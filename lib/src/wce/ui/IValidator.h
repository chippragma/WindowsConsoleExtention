#pragma once

#include <vector>
#include <string>

namespace wce {

template<class TValue>
class IValidator {
public:
    virtual ~IValidator() { }

    virtual bool validate(const TValue &value, std::vector<std::string> &outErrors) const = 0;
};

}



