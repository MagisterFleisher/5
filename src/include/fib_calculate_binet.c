#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <gmp.h>

/*** NOTE:
*    Due to float limitations, Binet's formula returns accurate results only up to, but not including, F33. */

/*****************************************
*  Binet's Formula
*
*  V1
*  F(n) = 1/sqrt(5) * (((1 + sqrt(5))/2)^n - ((1 - sqrt(5))/2)^n) 
*
*  a.k.a.
*
*  V2  
*  F(n) = 1/sqrt(5) * (Phi^n - (-(1/Phi))^n))
*
*  a.k.a.
*
*  V3
*  F(n) = (Phi^n - (-Phi)^-n)/sqrt(5)
*
*  a.k.a.
*
*  V4
*  F(n) = (Phi^n + (1-Ph)^2)/sqrt(5)
*
*******************************************/

const uint64_t      calculate_fibinacci_number_binet    (   const int fibinacci_number) {
    const float_t   inv_sqrt_5 = { 1/sqrt(5) };
    const float_t   phi = { (1 + sqrt(5)) / 2 };
    const float_t   anti_phi = { -1 / phi };
    
    //  V1
    return          (uint64_t) {
        inv_sqrt_5 * (pow(phi, fibinacci_number) - pow(anti_phi, fibinacci_number))
    };
}

void                calculate_fibinacci_number_binet_arbitrary_precision (   const int fibinacci_number) {
    mpf_t sqrt_5;
    mpf_t phi;
    mpf_t un_phi;
    mpf_t tmp_phi_pow;
    mpf_t tmp_un_phi_pow;
    mpf_t almost_fib;
    mpf_t float_fib_value;
    //mpf_t fib_value;

    /*
    *
    * sqrt(5)
    *
    */
    mpf_init(sqrt_5);
    mpf_set_si(sqrt_5, 5);
    mpf_sqrt(sqrt_5, sqrt_5);
    
    /*
    *
    * Phi = (1 + sqrt(5))/2
    *
    */
    mpf_init(phi);
    mpf_add_ui(phi, sqrt_5, 1);
    mpf_div_ui(phi, phi, 2);

    /*
    *
    * UnPhi = (1 - sqrt(5))/2
    *
    */
    mpf_init(un_phi);
    mpf_init_set(un_phi, sqrt_5);
    mpf_ui_sub(un_phi, 1, un_phi);

    mpf_div_ui(un_phi, un_phi, 2);

    /*
    *
    * Tmp_Phi_Pow = Phi ^ n
    *
    */
    mpf_init(tmp_phi_pow);
    mpf_pow_ui(tmp_phi_pow, phi, fibinacci_number);

    /*
    *
    * Tmp_UnPhi_Pow = UnPhi ^ n
    *
    */
    mpf_init(tmp_un_phi_pow);
    mpf_pow_ui(tmp_un_phi_pow, un_phi, fibinacci_number);

    /*
    *
    * Almost_Fib = Tmp_Phi_Pow - Temp_UnPhi_Pow
    *
    */
    mpf_init(almost_fib);
    mpf_sub(almost_fib, tmp_phi_pow, tmp_un_phi_pow);

    /*
    *
    *
    * Float_Fib_Value = Almost_Fib / sqrt(5) 
    *
    */
    mpf_init(float_fib_value);  
    mpf_div(float_fib_value, almost_fib, sqrt_5);

    /*
    *
    * Fib_Value = Round Float_Fib_Value
    *
    */
   // mpf_init(fib_value);
    //mpf_set(fib_value, almost_fib);
    //mpf_get_ui(fib_value, fib_value);

    printf("Sqrt 5: ");
    mpf_out_str(stdout, 10, 10, sqrt_5);

    printf("phi: ");
    mpf_out_str(stdout, 10, 10, phi);

    printf("\n Un-phi: ");
    mpf_out_str(stdout, 10, 10, un_phi);


    printf("\n tmp phi pow: ");
    mpf_out_str(stdout, 10, 10, tmp_phi_pow);


    printf("\n tmp  Un-phi pow: ");
    mpf_out_str(stdout, 10, 10, tmp_un_phi_pow);

    printf("\n Almost Fib: ");
    mpf_out_str(stdout, 10, 10, almost_fib);

    printf("\n Float Fib: ");
    mpf_out_str(stdout, 10, 40, float_fib_value);
/*
    printf("\nFibinacci number %d: ", fibinacci_number);

    mpf_out_str(stdout, 10, 10, fib_value);
    */
/*
    mpf_t sqrt_5;
    mpf_t phi;
    mpf_t un_phi;
    mpf_t tmp_phi_pow;
    mpf_t tmp_un_phi_pow;
    mpf_t float_fib_value;
    mpf_t almost_fib;
    mpf_t fib_value;
*/
    mpf_clear(sqrt_5);
    mpf_clear(phi);
    mpf_clear(un_phi);
    mpf_clear(tmp_un_phi_pow);
    mpf_clear(tmp_phi_pow);
    mpf_clear(almost_fib);
    mpf_clear(float_fib_value);
    //mpf_clear(fib_value);

    return;
}