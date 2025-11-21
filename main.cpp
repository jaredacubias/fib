#include "matrix2d.h"
#include "vec2.h"
#include "bigint.h"

#include <iostream>
#include <time.h>

int main() {
    auto fibm2x2 = m2x2(BigInt("0"), BigInt("1"), BigInt("1"), BigInt("1"));
    std::cout << "Enter a number for the n-th fibonacci number you want to find: ";
    int n;
    std::cin >> n;
    fibm2x2 = fibm2x2 ^ n; 
    auto fibv = vec2(BigInt("0"), BigInt("1"));
    auto ans = fibm2x2 * fibv;
    std::cout << "The " << n << "-th fibonacci number is " << ans.x() << '\n';
}