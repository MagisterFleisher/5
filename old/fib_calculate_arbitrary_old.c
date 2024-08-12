#include <stdio.h>
#include <gmp.h>
#include "fib_calculate_64.c"

void calculate_fibinacci_number_arbitrary_precision(const int fibinacci_number) {
    /** This function only gets called for fibinacci numbers past 93.
        The initializing values for the arbitrary precision fibinacci values
        begins by adding fib(92) + fib(93). */
    mpz_t fib0;
    mpz_init(fib0);
    mpz_set_ui(fib0, calculate_fibinacci_number(92));

    mpz_t fib1;
    mpz_init(fib1);
    mpz_set_ui(fib1, calculate_fibinacci_number(93));

    mpz_t fib2;
    mpz_init(fib2);
    mpz_set_ui(fib2, 0);
    mpz_add(fib2, fib0, fib1);

    if(fibinacci_number > 94) {
        for(int i = 94; i < fibinacci_number; i++ ) {
            mpz_set(fib0, fib1);
            mpz_set(fib1, fib2);
            mpz_add(fib2, fib0, fib1); } }
    
    printf("Fibinacci number %d: ", fibinacci_number);
    mpz_out_str(stdout, 10, fib2);

    mpz_clear(fib0);
    mpz_clear(fib1);
    mpz_clear(fib2);
    return; }