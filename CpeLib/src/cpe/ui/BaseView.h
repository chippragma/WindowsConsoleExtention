#pragma once

#include <vector>
#include <algorithm>

#include "cpe/ui/output/OutputHelper.h"
#include "IView.h"
#include "cpe/ui/ICuiElement.h"
#include "cpe/ui/IViewModel.h"

namespace cpe {

template<class TViewModel>
class BaseView : public IView {
public:
    using ViewModelClass = TViewModel;

    BaseView();

    ~BaseView() override;

    TViewModel &initialize();

    void show(bool beforeClean, bool afterClean) final;

protected:
    void on_initialize() override = 0;

    void on_before_show() override { };

    void on_after_show() override { };

    template<class TElement>
    void push(TElement &element);

private:
    IViewModel *mViewModel = nullptr;
    std::vector<ICuiElement *> mElements;
};

template<class TViewModel>
BaseView<TViewModel>::BaseView() {
    static_assert(std::is_base_of<IViewModel, TViewModel>::value);
}

template<class TViewModel>
BaseView<TViewModel>::~BaseView() {
    delete mViewModel;
}

template<class TViewModel>
TViewModel &BaseView<TViewModel>::initialize() {
    if (!mViewModel) {
        mViewModel = static_cast<IViewModel *>(new TViewModel());
        on_initialize();
    }
    return *(static_cast<TViewModel *>(mViewModel));
}

template<class TViewModel>
void BaseView<TViewModel>::show(bool beforeClean, bool afterClean) {
    if (beforeClean)
        term::clear();

    OutputHelper outHelp;
    if (afterClean)
        outHelp.saveState();
    on_before_show();
    for (ICuiElement *item : mElements)
        item->run(*mViewModel);
    on_after_show();
    if (afterClean)
        outHelp.backState();
}

template<class TViewModel>
template<class TElement>
void BaseView<TViewModel>::push(TElement &element) {
    mElements.push_back(static_cast<ICuiElement *>(&element));
}

}