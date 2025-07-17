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
const char* print_bits(uint8_t val) {
    // Using static so the array persists after the function returns.
    // Without static, bitstring would be stored on the stack and deleted after the function ends.
    static char bitstring[9];

    for (int i = 7; i >= 0; i--) {
        // Isolate bit i by shifting it to the rightmost position, then masking with & 1
        // This gives us 0 or 1 only. Then we convert it to the character '0' or '1'
        bitstring[7 - i] = ((val >> i) & 1) ? '1' : '0';
    }

    // Null-terminate the string so it can be printed like a normal C string
    bitstring[8] = '\0';

    return bitstring; // Return a pointer to the string
}

//Play around with these to get all the possible combinaisons of Bitwise
//Keep it under 2 to the power of 8 which is 256 for both of the ops
const uint8_t op1d=150, op2d=165;

int main() {


    //Bitwise AND Operation : &

    printf("The AND Operation of %s and %s is %s\n",
           print_bits(op1d), print_bits(op2d), print_bits(op1d & op2d));
    //Bitwise OR Operation : |

    printf("The OR Operation of %s or %s is %s\n",
           print_bits(op1d), print_bits(op2d), print_bits(op1d | op2d));

    //Bitwise XOR Operation : ^

    printf("The XOR Operation of %s or %s is %s\n",
           print_bits(op1d), print_bits(op2d), print_bits(op1d ^ op2d));

    //Bitwise NOT : ~

    printf("NOT of %s is %s and NOT of %s is %s\n",print_bits(op1d),print_bits(~op1d),print_bits(op2d),print_bits(~op2d));

    return 0;



}