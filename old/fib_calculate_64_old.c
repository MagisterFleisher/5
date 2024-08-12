#include <stdio.h>
#include <stdint.h>

const uint64_t calculate_fibinacci_number(const int fibinacci_number) {
    uintmax_t fibinacci_sequence[] = { 0, 1, 1 };

    if(fibinacci_number < 0) {
        printf("Error.  Fibinacci squence begins at 0.");
        return 1; }
    
    if(fibinacci_number <= 2) {
        printf("Fibinacci number %d: %llu\n", fibinacci_number, fibinacci_sequence[fibinacci_number]);
    } else {
        for(int i = 0; i < (fibinacci_number -2); i++) {
            fibinacci_sequence[0] = fibinacci_sequence[1];
            fibinacci_sequence[1] = fibinacci_sequence[2];
            fibinacci_sequence[2] = fibinacci_sequence[0] + fibinacci_sequence[1]; 
        }
        printf("Fibinacci number %d: %ju\n", fibinacci_number, fibinacci_sequence[2]); }

    return (fibinacci_sequence[2]);
}
