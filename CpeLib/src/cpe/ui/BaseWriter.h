#pragma once

#include "IWriter.h"
#include "BaseWriterData.h"
#include "cpe/ui/BaseCuiElement.h"

namespace cpe {

template<class TData>
class BaseWriter : public BaseCuiElement<TData>,
                   public IWriter {
    using _BaseCuiElement = BaseCuiElement<TData>;
public:
    static const int32_t MAX_HEIGHT = 128;

    ~BaseWriter() override { };

    void write(Buffer &buf) override;

    void run(IViewModel &ctrl) override;

    virtual void output_to(std::ostream &outStream);
};

template<class TData>
void BaseWriter<TData>::write(Buffer &buf) {
    on_write(buf);
}

template<class TData>
void BaseWriter<TData>::run(IViewModel &ctrl) {
    if (!static_cast<IElementData&>(_BaseCuiElement::data()).visible())
        return;
    _BaseCuiElement::fire_data(ctrl);
    output_to(std::cout);
}

template<class TData>
void BaseWriter<TData>::output_to(std::ostream &outStream) {
    Buffer buf(Point(
            static_cast<BaseWriterData &>(_BaseCuiElement::data()).width(),
            MAX_HEIGHT));
    on_write(buf);
    buf.output_to(outStream);
}

}



