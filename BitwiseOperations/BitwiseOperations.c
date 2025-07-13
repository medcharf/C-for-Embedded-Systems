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











/*


//Function to see the Bits instead of Decimal Values
const char* print_bits(uint8_t val) {
    static char bitstring[9];
    for (int i = 7; i >= 0; i--) {
        bitstring[7 - i] = ((val >> i) & 1) ? '1' : '0';
    }
    bitstring[8] = '\0';
    return bitstring;
}
//Play around with these to get all the possible combinaisons of Bitwise
//Keep it under 2 to the power of 8 which is 256 for both of the ops
const uint8_t op1d=150, op2d=165;
*/
int main() {
/*
    //Bitwise AND Operation : &

    printf("The AND Operation of %s and %s is %s\n",
           print_bits(op1d), print_bits(op2d), print_bits(op1d & op2d));
    //Bitwise OR Operation : |

    printf("The OR Operation of %d or %d is %d\n",op1,op2,op1|op2);

    //Bitwise XOR Operation : ^

    printf("The XOR Operation of %d or %d is %d\n",op1,op2,op1^op2);

    //Bitwise NOT : ~

    printf("NOT of %d is %u and NOT of %d is %u\n", op1,~op1,op2,~op2);

*/

    return 0;



}