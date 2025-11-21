#ifndef MATRIX2D
#define MATRIX2D

#include <cmath>
#include <iostream>
#include "vec2.h"
#include "bigint.h"

class matrix2d {
    public:
        BigInt e[2][2];

        matrix2d() : e { {BigInt("0"), BigInt("0")}, {BigInt("0"), BigInt("0")} } {};
        matrix2d(BigInt a, BigInt b, BigInt c, BigInt d) : e { {a, b}, {c, d} } {};

        BigInt a() const { return e[0][0]; }
        BigInt b() const { return e[0][1]; }
        BigInt c() const { return e[1][0]; }
        BigInt d() const { return e[1][1]; }
        
        matrix2d operator-() const { return matrix2d(-1*e[0][0], -1*e[0][1], -1*e[1][0], -1*e[1][1]) ; }
        
        matrix2d& operator*=(BigInt t) {
            e[0][0] *= t;
            e[0][1] *= t;
            e[1][0] *= t;
            e[1][1] *= t;
            return *this;
        }

        matrix2d& operator/=(BigInt t) {
            return *this *= 1/t;
        }
};
using m2x2 = matrix2d;

inline m2x2 operator+(const m2x2& a, const m2x2& b) {
    return m2x2(a.a() + b.a(), a.b() + b.b(), a.c() + b.c(), a.d() + b.d());
}

inline m2x2 operator-(const m2x2& a, const m2x2& b) {
    return m2x2(a.a() - b.a(), a.b() - b.b(), a.c() - b.c(), a.d() - b.d());
}



inline m2x2 operator*(BigInt t, const m2x2& a) {
    return m2x2(t * a.a() , t * a.b(), t * a.c(), t* a.d() );
}

inline m2x2 operator*(const m2x2& a, BigInt t) {
    return t * a;
}

inline m2x2 operator*(const m2x2& a, const m2x2& b) {
    return m2x2(
        a.a() * b.a() + a.b() * b.c(),
        a.a() * b.b() + a.b() * b.d(),
        a.c() * b.a() + a.d() * b.c(),
        a.c() * b.b() + a.d() * b.d()
    );
}

inline vec2 operator*(const m2x2& a, const vec2& v) {
    return vec2(
        a.a() * v[0] + a.b() * v[1],
        a.c() * v[0] + a.d() * v[1]
    );
}

inline m2x2 operator^(const m2x2& a, const int n) {
    if (n < 1) return a;
    m2x2 result = a;
    m2x2 currMult = a;
    for (int i = n - 1; i != 0; i = i >> 1) {
        if (1 & i) {
            result = currMult * result;
        }
        currMult = currMult * currMult;
    }
    return result;
}

inline std::ostream& operator<<(std::ostream& out, const m2x2& a) {
    return out << '[' << a.a() << ' ' << a.b() << ']' << '\n' << '[' << a.c() << ' ' << a.d() << ']';
}

#endif