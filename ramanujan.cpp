#include <iostream>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/math/constants/constants.hpp>
using boost::multiprecision::cpp_dec_float_50;

template <typename T>
T factorial(int n)
{
    T res = 1;
    for (int i = 1; i <= n; ++i)
    {
        res *= i;
    }
    return res;
}

int main() {

    cpp_dec_float_50 sum = 0;
    for (int k = 0; k < 100; ++k) {  
        cpp_dec_float_50 numerator = factorial<cpp_dec_float_50>(4 * k) * (1103 + 26390 * k);
        cpp_dec_float_50 denominator = pow(factorial<cpp_dec_float_50>(k), 4) * pow(396, 4 * k);
        sum += numerator / denominator;
    }
    cpp_dec_float_50 result = (2 * sqrt(2) / 9801) * sum;
    result = 1/ result;

    std::cout << "Ramanujan summation: " << result << "\n";
    std::cout << "Pi from boost library: " << boost::math::constants::pi<cpp_dec_float_50>() << "\n";

    return 0;
}

