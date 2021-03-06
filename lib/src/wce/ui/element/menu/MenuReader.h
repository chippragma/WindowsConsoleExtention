#pragma once

#include <set>
#include <cstdint>

#include "wce/ui/BaseReader.h"
#include "MenuItem.h"

namespace wce {

using MenuItemPair = std::pair<uint32_t, MenuItem*>;
using MenuItemSet = std::set<MenuItemPair>;
using MenuReaderResult = ReaderResult<uint32_t>;

class MenuReader : public BaseReader<MenuReader, uint32_t> {
public:
    ~MenuReader() override;

    void setCommandItems(MenuItemSet &itemList);

protected:
    MenuItemSet m_commandItems;

    bool onConvert(std::string &srcLine, uint32_t &convertedValue) override;
};

}




