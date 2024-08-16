#include <stdio.h>
#include <gmp.h>

void fib_calculate_gmp (const int fibinacci_number) {
    printf("\ngmp function ... %d\n", fibinacci_number);
    mpz_t fib_value;
    mpz_init(fib_value);
    mpz_fib_ui(fib_value, fibinacci_number);
    mpz_out_str(stdout, 10, fib_value);
    return;
}