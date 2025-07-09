#include <stdio.h>
#include <stdint.h>

// Simulate a memory-mapped hardware register
#define FAKE_HARDWARE_REG_ADDRESS ((volatile uint32_t*)0x40000000)
/* Fake ... is a pointer pointing at the adress 0x4... and the value of that mem is
of the type unsigned 32 bits */
void pointer_basics() {
    int a = 42;
    int *ptr = &a;

    printf("Pointer Basics:\n");
    printf("Address of a: %p\n", (void*)&a);
    printf("Pointer value (address): %p\n", (void*)ptr);
    printf("Dereferenced pointer value: %d\n", *ptr);
    printf("---------------------------\n");
}

void pointer_arithmetic() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr;

    printf("Pointer Arithmetic:\n");
    printf("arr[0] = %d\n", *ptr);
    printf("arr[1] = %d\n", *(ptr + 1));
    printf("arr[2] = %d\n", *(ptr + 2));
    printf("---------------------------\n");
}

void volatile_pointer_example() {
    volatile int x = 5;
    volatile int *ptr = &x;

    printf("Volatile Pointer:\n");
    printf("Value of x: %d\n", *ptr);

    *ptr = 10; // The compiler won't optimize this out
    printf("Modified x: %d\n", *ptr);
    printf("---------------------------\n");
}

void memory_mapped_io_example() {
    printf("Simulated Memory-Mapped I/O:\n");
    volatile uint32_t *reg = FAKE_HARDWARE_REG_ADDRESS;

    // Normally you can't do this on a PC, this is for educational purposes
    printf("Writing 0xABCD1234 to fake register address: %p\n", (void*)reg);
    // *reg = 0xABCD1234; // Unsafe unless you're actually on an embedded system
    printf("Reading from fake register (simulated, not actually reading): 0x????\n");
    printf("---------------------------\n");
}

int main() {
    pointer_basics();
    pointer_arithmetic();
    volatile_pointer_example();
    memory_mapped_io_example();

    return 0;
}
