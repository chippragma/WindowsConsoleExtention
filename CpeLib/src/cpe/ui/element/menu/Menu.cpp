#include "Menu.h"

namespace cpe {

Menu::~Menu() {
    for (auto item : mItems)
        delete item.second;
}

const StyledBorder &Menu::getBorder() const {
    return mBorder;
}

StyledBorder &Menu::getBorderRef() {
    return mBorder;
}

const StyledText &Menu::getCaption() const {
    return mCaption;
}

StyledText &Menu::getCaptionRef() {
    return mCaption;
}

const StyledText &Menu::getReaderHint() const {
    return mReaderHint;
}

StyledText &Menu::getReaderHintRef() {
    return mReaderHint;
}

const TextColor &Menu::getCommandColor() const {
    return mCommandColor;
}

TextColor &Menu::getCommandColorRef() {
    return mCommandColor;
}

void Menu::assignReader(MenuReader &reader) {
    mReader = &reader;
}

bool Menu::removeItem(uint32_t itemId) {
    auto find = std::find_if(
        mItems.cbegin(), mItems.cend(),
        [&](const IMenuItemPair &pair) {
            return pair.first == itemId;
        });
    if (find != mItems.cend()) {
        mItems.erase(find);
        return true;
    }
    return false;
}

void Menu::onWrite(Buffer &buf) {
    using BS = BorderStyle;

    const auto &brd = this->getBorderRef();
    buf.draw(brd[BS::SLT] + ' ');

    {
        auto captionBuf = buf.extract(buf.getCursorPos(), buf.getSize() - buf.getCursorPos());
        captionBuf.drawLine(this->getCaption());
        buf.getCursorPosRef() = Point(0, 1);
        buf.draw(brd[BS::SL], captionBuf.getUsedSize().getY() - 1, true);
    }

    for (const auto &pair : mItems) {
        if (!pair.second->getVisible())
            continue;
        auto sumBuf = buf.extract(buf.getCursorPos(), buf.getSize() - buf.getCursorPos());
        pair.second->write(sumBuf, brd, this->getCommandColor());
        buf.getCursorPosRef().getXRef() = 0;
        buf.getCursorPosRef().getYRef()++;
        buf.draw(brd[BS::SL], sumBuf.getUsedSize().getY() - 1, true);
    }

    buf.getCursorPosRef().getXRef() = 0;
    buf.draw(brd[BS::SLB] + ' ');

    {
        auto inputMsg = buf.extract(buf.getCursorPos(), buf.getSize() - buf.getCursorPos());
        inputMsg.drawLine(this->getReaderHintRef());
    }
}

void Menu::onAfterRun() {
    if (mReader) {
        MenuItemVector vec;
        for (auto& item : mItems) {
            auto comItem = dynamic_cast<MenuItem*>(item.second);
            if (comItem)
                vec.emplace_back(item.first, comItem);
        }
        mReader->setCommandItems(vec);
    }
}

}