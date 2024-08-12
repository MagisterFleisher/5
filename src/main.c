#include <stdio.h>
#include <stdlib.h>
#include "include/fib_calculate.h"

const int parse_argument_string_to_number_value(char** argument_vector);
const int print_title(void);
const int print_exit(void);
const int print_argument_information(const int arguments_count, char** argument_vector);

int main(int argument_count, char** argument_vector) {
    
    /** Title **********************************************************************************/
    const int title_return_errors = { 
        print_title() };

    if(title_return_errors != 0) {
        printf("Error detected generating title.  Exiting .....\n");
        return 1; }

    /** Body  **********************************************************************************/
    const int print_argument_return_errors = { 
        print_argument_information(argument_count, argument_vector) };

    if(print_argument_return_errors != 0) {
        printf("Error detected printing arguments.  Exiting .....\n");
        return 1; }

    /** Read command line argument for number ***************************************************/
    const int fibinacci_number = {
        parse_argument_string_to_number_value(argument_vector) };
    if(fibinacci_number == -1) {
        printf("Error reading argument for fibinacci sequence number.  Exiting ...\n");
        return 1; }

    if(fibinacci_number <= 93) {
        const uint64_t fibinacci_value = { calculate_fibinacci_number(fibinacci_number) };
        printf("Fibinacci number %d: %ju\n\n", fibinacci_number, fibinacci_value);
    } else {
        printf("Fibinacci number %d requires greater than 64 bits.\n\n", fibinacci_number);
        printf("Using GMP library to calculate with arbitrary precision.\n\n");
        /****** GMP Arbitrary Precision stuff */
        calculate_fibinacci_number_arbitrary_precision(fibinacci_number);
    }

    /** Exit  ************************************************************************************/
    const int exit_return_errors = { 
        print_exit() };

    if(exit_return_errors != 0) {
        printf("Error detected exit information.  Exiting .....\n");
        return 1; }


    return 0;
}

const int print_title(void) {

    printf("\nFibinacci Generator!\n");
    printf("(Using GMP for abritrary precision integers!)\n");
    printf("--------------------\n\n");

    return 0;
}

const int print_exit(void) {

    printf("\n--------------------\n\n");
    printf("Exiting program ...\n\n");
    return 0;
}

const int print_argument_information(const int argument_count, char** argument_vector) {

    printf("Number of command line arguments: %d\n\n", argument_count);

    if(argument_count > 1) {
        for(int i = 0; i < argument_count; i++) {
        printf("Command line argument %d: %s\n\n", (i + 1), argument_vector[i]); }
    } else {
        printf("Insufficient arguments to run fibinacci generator.\n");
        return 1; }

    return 0;
}

const int parse_argument_string_to_number_value(char** argument_vector) {
    char* endptr;
    const int argument_value = (int) {
        strtol(argument_vector[1], &endptr, 10) };

    if(endptr == argument_vector[1]) {
        printf("No valid argument found.\n");
        return -1;
    } else if (*endptr != '\0') {
        printf("Invalid character: %c\n", *endptr);
        return -1;
    } else {
        return argument_value; }

    return -1;
}