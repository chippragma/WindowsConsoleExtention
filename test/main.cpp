#include <iostream>
#include <vector>
#include <cmath>
#include <cpe/ui/command/Label.h>

#include "cpe/core/Encoder.h"
#include "cpe/ui/Script.h"

#include "TestProcessor.h"

using namespace cpe;

namespace {

Encoder<Encoding::UTF8> encUtf8;
Encoder<Encoding::CP866> encCp866;

std::string encode(const std::string &src) {
    return encCp866.to(encUtf8.from(src));
}

}

int main() {
    term::setTitle(L"Текст консоли");
    term::setForeColor(Colors::WHITE);
    term::setBackColor(Colors::BLACK);

    std::cout << encode("Кодировка вывода: ") << term::getWriterCp() << "\n";
    std::cout << encode("Кодировка ввода: ") << term::getWriterCp() << std::endl;
    std::cout << encode("\u255F\n\n");

    term::pause();

    Script<TestProcessor> script;
    auto proc = script.processor();
    auto item = script.add<Label>();
    item->text->set("it's MESSAGE!");
    item->style.fore->set(cpe::Colors::BLUE);
    item->style.back->set(cpe::Colors::LT_TEAL);
    script.run();
    script.run();
    item->text->set(encode("11"));
    script.run();


//    std::cout << ctrl.getStateText() << std::endl;

    term::pause();

    return 0;
}
