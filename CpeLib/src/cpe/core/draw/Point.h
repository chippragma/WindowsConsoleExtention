#pragma once

#include <string>
#include <cstdint>

namespace cpe {

class Point {
public:
    enum Location : int8_t {
        PL_ZERO = 0,
        PL_X = 1,
        PL_Y = 2,
        PL_NEGATIVE_X = 4,
        PL_NEGATIVE_Y = 8,
        PL_SECTOR_I = PL_X | PL_Y,
        PL_SECTOR_II = PL_X | PL_Y | PL_NEGATIVE_X,
        PL_SECTOR_III = PL_X | PL_Y | PL_NEGATIVE_Y | PL_NEGATIVE_X,
        PL_SECTOR_VI = PL_X | PL_Y | PL_NEGATIVE_Y,
    };

    Point();

    Point(int32_t x, int32_t y);

    const int32_t& getX() const;

    int32_t& getXRef();

    const int32_t& getY() const;

    int32_t& getYRef();

    Location getLocation() const;

    std::string toString() const;

    Point &operator+=(const Point &p1);

    Point operator+(const Point &p1) const;

    Point &operator-=(const Point &p1);

    Point operator-(const Point &p1) const;

    Point &operator+=(int32_t k);

    Point operator+(int32_t k) const;

    Point &operator-=(int32_t k);

    Point operator-(int32_t k) const;

    Point &operator*=(int32_t k);

    Point operator*(int32_t k) const;

    Point &operator/=(int32_t k);

    Point operator/(int32_t k) const;

    bool operator==(const Point &point) const;

    bool operator!=(const Point &point) const;

protected:
    int32_t mX;
    int32_t mY;
};

}
