#include "graphlib/utils/math_utils.hpp"
using namespace graphlib::utils;

int main() {
    precompute_factorials();

    cout << "5^13 % MOD = " << binexp(5, 13) << endl;
    cout << "Modular inverse of 17 mod 1e9+7 = " << modinv(17) << endl;

    cout << "10C3 = " << nCr(10, 3) << endl;
    cout << "10P3 = " << nPr(10, 3) << endl;

    cout << "Fibonacci(50) = " << nth_fib(50) << endl;

    return 0;
}
