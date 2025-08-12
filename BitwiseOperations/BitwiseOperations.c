#include "stdio.h"
#include "stdint.h"
/*Explaining Static usage
Let's say we have a function for incrementing a variable each time something in the
code happens */
int adder=0;

int incr(int adder) {
    return adder++;
}
//we can replace all of this by using static
int incr_static() {
    static int static_incr = 0;
    static_incr++;
}

//Function to see the Bits instead of Decimal Values
void print_bits(uint8_t val, char *bitstring) {
    // Using the buffer provided by the caller instead of static inside function

    for (int i = 7; i >= 0; i--) {
        // Isolate bit i by shifting it to the rightmost position, then masking with & 1
        // This gives us 0 or 1 only. Then we convert it to the character '0' or '1'
        bitstring[7 - i] = ((val >> i) & 1) ? '1' : '0';
    }

    // Null-terminate the string so it can be printed like a normal C string
    bitstring[8] = '\0';
}


//Play around with these to get all the possible combinaisons of Bitwise
//Keep it under 2 to the power of 8 which is 256 for both of the ops
const uint8_t op1d=150, op2d=165;
int main() {
    char b1[9], b2[9], b3[9];

    //Bitwise AND Operation : &
    print_bits(op1d, b1);
    print_bits(op2d, b2);
    print_bits(op1d & op2d, b3);
    printf("The AND Operation of %s and %s is %s\n", b1, b2, b3);

    //Bitwise OR Operation : |
    print_bits(op1d, b1);
    print_bits(op2d, b2);
    print_bits(op1d | op2d, b3);
    printf("The OR Operation of %s or %s is %s\n", b1, b2, b3);

    //Bitwise XOR Operation : ^
    print_bits(op1d, b1);
    print_bits(op2d, b2);
    print_bits(op1d ^ op2d, b3);
    printf("The XOR Operation of %s or %s is %s\n", b1, b2, b3);

    //Bitwise NOT : ~
    print_bits(op1d, b1);
    print_bits(~op1d, b2);
    print_bits(op2d, b3);
    char b4[9];
    print_bits(~op2d, b4);
    printf("NOT of %s is %s and NOT of %s is %s\n", b1, b2, b3, b4);

    return 0;
}
