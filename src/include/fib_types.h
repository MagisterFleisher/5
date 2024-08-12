#include <gmp.h>
#include <stdint.h>
/*
Attempt to de-duplicate ways of storing fibinacci values
 
union fib_value {
    uint64_t fibinacci_value_64;
    mpz_t fibinacci_value_arbitrary;
};
*/