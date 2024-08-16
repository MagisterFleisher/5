#include <stdint.h>
#include <math.h>

/*** NOTE:
*    Due to float limitations, alternate analytic formula returns accurate results only up to, but not including, F33. */


/*****************************************
*  Alternate Analytic Fibinacci Formula
*  F(n) = (Phi ^n - (cos(pi * n)* (Phi ^-n))) / sqrt(5) 
*
*******************************************/

const uint64_t      calculate_fibinacci_number_alt_analytic (   const int fibinacci_number) {
    const float_t   inv_sqrt_5  = { 1/sqrt(5) };
    const float_t   phi         = { (1 + sqrt(5)) / 2 };

    return  (uint64_t) {
        inv_sqrt_5 * (pow(phi,fibinacci_number) - (cos(fibinacci_number * M_PI) * pow(phi, (-1 * fibinacci_number))))
    };
    }

void      calculate_fibinacci_number_alt_analytic_arbitrary_precision (   const int fibinacci_number) {
    const float_t   inv_sqrt_5  = { 1/sqrt(5) };
    const float_t   phi         = { (1 + sqrt(5)) / 2 };

/*    return  (uint64_t) {
        inv_sqrt_5 * (pow(phi,fibinacci_number) - (cos(fibinacci_number * M_PI) * pow(phi, (-1 * fibinacci_number))))
    }; */
    return;
    }