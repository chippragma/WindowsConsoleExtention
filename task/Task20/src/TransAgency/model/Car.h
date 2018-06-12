#pragma once

#include <string>

#include <cpe/ui/IModel.h>
#include <cpe/core/ISerializable.h>
#include <ostream>

class Car : public cpe::IModel,
            public cpe::ISerializable {
public:
    enum Fields : uint32_t {
        CF_MARK,
        CF_MAKER,
        CF_SEATS,
        CF_STATE_NUMBER
    };

    ~Car() override;

    const std::string &getMark() const;

    std::string &getMark();

    const std::string &getMaker() const;

    std::string &getMaker();

    const uint32_t &getSeats() const;

    uint32_t &getSeats();

    const std::string &getStateNumber() const;

    std::string &getStateNumber();

    bool getFieldValue(uint32_t idField, std::string &outField) const override;

    std::string toString() const override;

protected:
    void onSerialize(std::ostream &os) const override;

    void onDeserialize(std::istream &is) const override;

private:
    std::string mMark;
    std::string mMaker;
    uint32_t mSeats;
    std::string mStateNumber;
};

