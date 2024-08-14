#include <stdint.h>
#include "fib_calculate.c"
#include "fib_calculate_binet.c"
#include "fib_calculate_alt_analytic.c"

/* fib_calculate.c              */
const uint64_t  calculate_fibinacci_number  (   const int fibinacci_number    );
void            calculate_fibinacci_number_arbitrary_precision  (   const int fibinacci_number    );

/* fib_calculate_binet.c        */
const uint64_t  calculate_fibinacci_number_binet    (       const int fibinacci_number  );

/* fib_calculate_alt_analytic.c */
const uint64_t  calculate_fibinacci_number_alt_analytic (   const int fibinacci_number  );