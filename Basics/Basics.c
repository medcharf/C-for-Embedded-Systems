#include <stdint.h>   // For fixed-width types like uint8_t
#include <stdio.h>    // For printf (used in simulation only)

// Define constants
#define MAX_SENSOR_VALUE 1023      // Max value for a 10-bit ADC
const float SENSOR_SCALE = 3.3f / MAX_SENSOR_VALUE; // const is better for typed constants

// Define a struct to group sensor data
typedef struct {
    uint16_t raw_value;
    float voltage;
    char unit[3];  // e.g., "V" for Volts
} SensorReading;

// Function to simulate ADC reading and convert to voltage
SensorReading read_sensor(uint16_t adc_value) {
    SensorReading reading;

    // Pass by value: adc_value is copied into the function
    reading.raw_value = adc_value;
    reading.voltage = adc_value * SENSOR_SCALE;

    // Set the unit (not very embedded-realistic, just to demo struct strings)
    reading.unit[0] = 'V';
    reading.unit[1] = '\0';

    return reading; // Return the entire struct
}

int main(void) {
    // Variables with embedded-style types
    uint8_t counter = 0;
    uint16_t adc_value = 600;

    // Call the function to get a sensor reading
    SensorReading r = read_sensor(adc_value);

    // Simulated printf (in real embedded, you'd send this over UART)
    printf("Raw ADC: %d\n", r.raw_value);
    printf("Voltage: %.2f %s\n", r.voltage, r.unit);

    // Basic control structures
    if (r.voltage > 2.0f) {
        printf("Voltage is high\n");
    } else {
        printf("Voltage is normal\n");
    }

    // For loop example (blinking LED in embedded context)
    for (counter = 0; counter < 5; counter++) {
        printf("Blink LED %d\n", counter + 1);
        // In real embedded: toggle GPIO here
    }

    // While loop example
    uint8_t timeout = 3;
    while (timeout > 0) {
        printf("Waiting... (%d)\n", timeout);
        timeout--;
    }

    // Switch-case example
    uint8_t command = 1;
    switch (command) {
        case 0:
            printf("System Idle\n");
            break;
        case 1:
            printf("System Running\n");
            break;
        case 2:
            printf("System Error\n");
            break;
        default:
            printf("Unknown Command\n");
            break;
    }

    return 0;
}
