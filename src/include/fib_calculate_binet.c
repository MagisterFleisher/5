#include <stdint.h>
#include <math.h>

/*** NOTE:
*    Due to float limitations, Binet's formula returns accurate results only up to, but not including, F33. */

/*****************************************
*  Binet's Formula
*  F(n) = 1/sqrt(5) * (((1 + sqrt(5))/2)^n - ((1 - sqrt(5))/2)^n) 
*
*  a.k.a.
*
*  F(n) = 1/sqrt(5) * (Phi^n - (-(1/Phi))^n))
*
*  a.k.a.
*
*  F(n) = (Phi^n - (-Phi)^-n)/sqrt(5)
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