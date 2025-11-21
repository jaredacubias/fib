#include "matrix2d.h"
#include "vec2.h"
#include "bigint.h"

#include <iostream>
#include <chrono>
#include <stdio.h>

BigInt fiblinear(int n);
BigInt fibrecursion(int n);

int main() {
    
    std::cout << "Enter a number for the n-th fibonacci number you want to find: ";
    int n;
    std::cin >> n;

    // Linear Algebra Implementation
    
    auto start = std::chrono::high_resolution_clock::now();
    BigInt resultlinear = fiblinear(n);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    long long timeElapsedLA = duration.count();
    std::cout << "The " << n << "-th fibonacci number is " << resultlinear << '\n';

    std::cout << "Time elasped: " << timeElapsedLA << " nanoseconds.\n";
    
    
    // Recursion Implementation
    /**
    auto start = std::chrono::high_resolution_clock::now();
    BigInt resultrecursion = fibrecursion(n);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    long long timeElapsedRec = duration.count();
    std::cout << "The " << n << "-th fibonacci number is " << resultrecursion << '\n';
    std::cout << "Time elasped: " << timeElapsedRec << " nanoseconds.\n";
    float percentDiff = (timeElapsedLA/timeElapsedRec) * 100;
    
    printf("The Linear Algebra implementation takes %.10f%% of the time as the recursion time!\n", percentDiff); 
    */
    
}

BigInt fiblinear(int n) {
    auto fibm2x2 = m2x2(BigInt("0"), BigInt("1"), BigInt("1"), BigInt("1"));
    fibm2x2 = fibm2x2 ^ n; 
    auto fibv = vec2(BigInt("0"), BigInt("1"));
    auto ans = fibm2x2 * fibv;
    return ans.x();
}

BigInt fibrecursion(int n) {
    if (n == 1 || n == 2)
    {
        return BigInt("1");
    }
    return fibrecursion(n - 2) + fibrecursion(n - 1);
}