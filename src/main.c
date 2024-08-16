#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include <zlib.h>
#include "include/fib_calculate.h"

enum command_options {
    QUIT = 'Q',
    FIBINACCI_CALCULATE = 'F',
    BINET_CALCULATE = 'B',
    ALT_ANALYTIC_CALCULATE = 'A',
    GMP = 'G'
};

const int   parse_argument_string_to_number_value ( char** argument_vector  );
const int   print_title   ( void    );
const int   print_exit    ( void    );
const int   print_argument_information    ( const int arguments_count, char** argument_vector   );
const int   repl          ( void    );

int     main(int argument_count, char** argument_vector ) {
    
    /** Title **********************************************************************************/
    const int   title_return_errors = { 
        print_title() };

    if  (   title_return_errors != 0) {
        (void)  printf("Error detected generating title.  Exiting .....\n");
        return 1; }

    /** Body  **********************************************************************************/
    
    const int   repl_errors = {
        repl() };
    if  (   repl_errors != 0) {
        return 1; }

    /** Exit  ************************************************************************************/
    const int   exit_return_errors = { 
        print_exit() };

    if  (   exit_return_errors != 0) {
        (void)  printf("Error detected exit information.  Exiting .....\n");
        return 1; }

    return 0;
}

const int   print_title(    void    ) {

    (void)  printf("\nFibinacci Generator!\n");
    (void)  printf("(Using GMP for abritrary precision integers!)\n");
    (void)  printf("--------------------\n\n");

    return  0;
}

const int   print_exit( void    ) {

    (void)  printf("\n--------------------\n\n");
    (void)  printf("Exiting program ...\n\n");
    return  0;
}

const int   print_argument_information( const int argument_count, char** argument_vector    ) {

    (void)  printf("Number of command line arguments: %d\n\n", argument_count);

    if  (   argument_count > 1  ) {
        for (   int i = 0; i < argument_count; i++) {
        (void)  printf("Command line argument %d: %s\n\n", (i + 1), argument_vector[i]); }
    } else {
        (void)  printf("Insufficient arguments to run fibinacci generator.\n");
        return  1; }

    return 0;
}

const int   parse_argument_string_to_number_value(  char** argument_vector  ) {
    char*   endptr;
    const int argument_value = (int) {
        strtol(argument_vector[1], &endptr, 10) };

    if( endptr == argument_vector[1]) {
        (void)  printf("No valid argument found.\n");
        return  -1;
    } else if ( *endptr != '\0') {
        (void) printf("Invalid character: %c\n", *endptr);
        return -1;
    } else {
        return  argument_value; }

    return -1;
}

/*** TODO:  Implement trimming whitespace */
/*** TODO:  Add timeout functionality 
                Could use multithreading to do this.
            Could use an optional for allowing both */
const int   repl(   void    ) {
    while(  true    ) {
        char    command_str[10];
        (void)  printf("\n\n [Q]uit [F]ibinacci calculate [B]inet\'s formula calculate [A]lternate Analytic calculate [G]MP fibinacci function");
        (void)  printf("\n\n> ");
        (void)  fgets(command_str, sizeof(command_str), stdin);
        (void)  printf("Command: %s", command_str);

        switch( toupper(command_str[0])) {
            case QUIT: {
                (void)  printf("\n Quitting...");
                return  0;
            };
            case FIBINACCI_CALCULATE : {
                (void)  printf("\nCalculate Fibinacci Number %c\n", command_str[2]);
                char*   endptr;
                char*   fib_char = &command_str[2];
                const int   fibinacci_number = (int) {
                    strtol(fib_char, &endptr, 10) };
                
                if( fibinacci_number <= 93) {
                    clock_t start_time = { clock() };
                    const uint64_t  fibinacci_value = { calculate_fibinacci_number(fibinacci_number) };
                    clock_t time_spent = { clock() - start_time};
                    
                    (void)  printf("Fibinacci number %d: %ju\n\n", fibinacci_number, fibinacci_value);
                    (void)  printf("\nTime spent calculating: %f ms", (((float) time_spent / CLOCKS_PER_SEC)) * 1000);
                } else {
                    (void)  printf("Fibinacci number %d requires greater than 64 bits.\n\n", fibinacci_number);
                    (void)  printf("Using GMP library to calculate with arbitrary precision.\n\n");
                    /****** GMP Arbitrary Precision stuff */
                    
                    clock_t start_time = { clock() };
                    (void)  calculate_fibinacci_number_arbitrary_precision(fibinacci_number);
                    clock_t time_spent = { clock() - start_time };
                    
                    (void)  printf("\nTime spent calculating: %f ms", (((float) time_spent / CLOCKS_PER_SEC)) * 1000);
                }
                break;
            };
            case BINET_CALCULATE : {
                (void)  printf("\nCalculate Fibinacci Number %c\n", command_str[2]);
                char*   endptr;
                char*   fib_char = &command_str[2];
                const int fibinacci_number = (int) {
                    strtol(fib_char, &endptr, 10) };
                
                if( fibinacci_number <= 33) {
                    clock_t start_time =    { clock() };
                    const   uint64_t        fibinacci_value_binet = { calculate_fibinacci_number_binet(fibinacci_number) };
                    clock_t time_spent =    { clock() - start_time};
                    
                    (void)  printf("Binet\'s formula\nFibinacci number %d: %ju\n\n", fibinacci_number, fibinacci_value_binet);
                    (void)  printf("\nTime spent calculating: %f ms", (((float) time_spent / CLOCKS_PER_SEC)) * 1000);
                } else {
                    clock_t start_time =    { clock() };
                    (void)  calculate_fibinacci_number_binet_arbitrary_precision(fibinacci_number);
                    clock_t time_spent =    { clock() - start_time};
                    
                    (void)  printf("\nTime spent calculating: %f ms", (((float) time_spent / CLOCKS_PER_SEC)) * 1000);
                }
                break;
            };
            case ALT_ANALYTIC_CALCULATE : {
                (void)  printf("\nCalculate Fibinacci Number %c\n", command_str[2]);
                char*   endptr;
                char*   fib_char = &command_str[2];
                const int fibinacci_number = (int) {
                    strtol(fib_char, &endptr, 10) };
                
                clock_t start_time = { clock() };
                const uint64_t fibinacci_value_alt_analytic = { calculate_fibinacci_number_alt_analytic(fibinacci_number) };
                clock_t time_spent = { clock() - start_time};
                    
                (void)  printf("Alternate Analytic formula\nFibinacci number %d: %ju\n\n", fibinacci_number, fibinacci_value_alt_analytic);
                (void)  printf("\nTime spent calculating: %f ms", (((float) time_spent / CLOCKS_PER_SEC)) * 1000);
                break;
            };
            default: {
                break;
            }; 
        }
    }
    return 0;
}
