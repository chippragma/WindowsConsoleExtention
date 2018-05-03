#pragma once

#include <map>
#include <list>
#include <algorithm>

#include "cpe/macros.h"
#include "ViewInterface.h"
#include "ControllerInterface.h"
#include "cpe/ui/element/ElementAbstract.h"
#include "ViewException.h"

namespace cpe {

template<class TController>
class ViewAbstract : public ViewInterface {
public:
    ViewAbstract();

    ~ViewAbstract();

    TController& initialize();

    void run() override;

protected:
    template<class TElement>
    TElement &addElement();

    virtual void initElements() = 0;

private:
    TController *_mController = nullptr;
    std::vector<ElementAbstract *> _mElements;
};

template<class TController>
ViewAbstract<TController>::ViewAbstract() {
    CPE_MACROS_StaticCheckBaseClass(ControllerInterface, TController);
}

template<class TController>
ViewAbstract<TController>::~ViewAbstract() {
    for (auto elem : _mElements)
        delete elem;
    _mElements.clear();
    delete _mController;
}

template<class TController>
TController &ViewAbstract<TController>::initialize() {
    if (!_mController) {
        _mController = new TController();
        initElements();
    }
    return *_mController;
}

template<class TController>
void ViewAbstract<TController>::run() {
    if (!_mController)
        throw ViewException("Controller has not been created");

    for (auto elem : _mElements) {
        elem->run(*_mController);
        elem->buffer().flush();
    }
}

template<class TController>
template<class TElement>
TElement &ViewAbstract<TController>::addElement() {
    CPE_MACROS_StaticCheckBaseClass(ElementAbstract, TElement);

    auto elem = new TElement();
    _mElements.push_back(elem);
    return *elem;
}

}




