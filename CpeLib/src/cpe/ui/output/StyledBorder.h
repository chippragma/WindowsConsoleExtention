#pragma once

#include "cpe/ui/style/TextColor.h"
#include "cpe/ui/style/BorderStyle.h"
#include "StyledChar.h"

namespace cpe {

class StyledBorder {
public:
    StyledBorder() = default;

    explicit StyledBorder(const BorderStyle& border);

    StyledBorder(const BorderStyle& border, const TextColor& color);

    const TextColor &color() const;

    TextColor &color();

    void color(const TextColor &color);

    const BorderStyle& style() const;

    BorderStyle& style();

    StyledChar at(const BorderStyle::Side &side) const;

    StyledChar operator[](const BorderStyle::Side &side) const;

private:
    TextColor mColor;
    BorderStyle mBorder;
};

}




