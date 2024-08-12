#include <stdint.h>
#include <math.h>

/*****************************************
*  Binet's Formula
*  F(n) = 1/sqrt(5) * (((1 + sqrt(5))/2)^n - ((1 - sqrt(5))/2)^n) 
*
*  a.ka.
*
*  F(n) = 1/sqrt(5) * (Phi^n - (-(1/Phi))^n))
*
*******************************************/

const uint64_t calculate_fibinacci_number_binet(const int fibinacci_number) {
    const float_t inv_sqrt_5 = { 1/sqrt(5) };
    const float_t phi = { (1 + sqrt(5)) / 2 };
    const float_t anti_phi = { -1 / phi };

    const uint64_t fibinacci_value = (uint64_t) {
        inv_sqrt_5 * (pow(phi, fibinacci_number) - pow(anti_phi, fibinacci_number))
    };
    return fibinacci_value;
}