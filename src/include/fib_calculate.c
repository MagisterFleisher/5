#include <stdio.h>
#include <stdint.h>
#include <gmp.h>

const uint64_t  calculate_fibinacci_number  ( const int fibinacci_number  ) {
    uintmax_t   fibinacci_sequence[] = { 0, 1, 1 };

    if  ( fibinacci_number < 0) {
        printf("Error.  Fibinacci squence begins at 0.");
        return 1; }
    
    if  ( fibinacci_number <= 2) {
        return  (   fibinacci_sequence[fibinacci_number]    );
        // printf("Fibinacci number %d: %ju\n", fibinacci_number, (unsigned long long) fibinacci_sequence[fibinacci_number]);
    } else {
        for (    int i = 0; i < (fibinacci_number -2); i++   )  {
            fibinacci_sequence[0] = fibinacci_sequence[1];
            fibinacci_sequence[1] = fibinacci_sequence[2];
            fibinacci_sequence[2] = fibinacci_sequence[0] + fibinacci_sequence[1]; 
        }
    }

    return (    fibinacci_sequence[2]   );
    }

void calculate_fibinacci_number_arbitrary_precision(const int fibinacci_number) {
    /** This function only gets called for fibinacci numbers past 93.
        The initializing values for the arbitrary precision fibinacci values
        begins by adding fib(92) + fib(93). */
    mpz_t   fib0;
    mpz_init(   fib0);
    mpz_set_ui( fib0, calculate_fibinacci_number(92));

    mpz_t   fib1;
    mpz_init(   fib1);
    mpz_set_ui( fib1, calculate_fibinacci_number(93));

    mpz_t   fib2;
    mpz_init(   fib2);
    mpz_set_ui( fib2, 0);
    mpz_add(    fib2, fib0, fib1);

    if  (   fibinacci_number > 94) {
        for (   int i = 94; i < fibinacci_number; i++ ) {
            mpz_set(fib0, fib1);
            mpz_set(fib1, fib2);
            mpz_add(fib2, fib0, fib1); } }
    
    printf("Fibinacci number %d: ", fibinacci_number);
    mpz_out_str(stdout, 10, fib2);

    mpz_clear(fib0);
    mpz_clear(fib1);
    mpz_clear(fib2);
    return; 
    }