#ifndef VEC2_H
#define VEC2_H

#include <cmath>
#include <iostream>
#include "bigint.h"
class vec2 {
    public:
        BigInt e[2];
        vec2() : e{BigInt("0"), BigInt("0")} {}
        vec2(BigInt e0, BigInt e1) : e{e0, e1} {}

        BigInt x() const { return e[0]; }
        BigInt y() const { return e[1]; }

        vec2 operator-() const { return vec2(-1*e[0], -1*e[1]); }
        BigInt operator[](int i) const { return e[i]; }
        BigInt& operator[](int i) { return e[i]; }

};

inline std::ostream& operator<<(std::ostream& out, const vec2& v) {
    return out << v.e[0] << ' ' << v.e[1];
}

#endif