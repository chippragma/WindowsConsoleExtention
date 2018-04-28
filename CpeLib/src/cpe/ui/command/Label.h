#pragma once

#include <string>
#include <cpe/ui/Buffer.h>

#include "cpe/core/Color.h"
#include "ACommand.h"
#include "cpe/utils/property/AProperties.h"

namespace cpe {

class Label : public ACommand, public AProperties {
public:
    /**
     * Стиль вывода
     */
    struct {
        Property<cpe::Color> back;
        Property<cpe::Color> fore;
    } style;

    Label();

    ~Label() override;

    Property<std::string> text;

    void *run(Buffer &buf, std::vector<AReader *> &readers) override;
};


}



