#pragma once

#include <vector>

#include <cpe/ui/BaseViewModel.h>
#include <cpe/ui/element/table/DataTable.h>

#include "TransAgency/model/Car.h"

class CarListVM : public cpe::BaseViewModel {
public:
    CarListVM();

    ~CarListVM() override;

    void onDataTableInit(cpe::DataTableData& data);

protected:
    void onAfterShow() override;

private:
    std::vector<Car> mCarList;
};


