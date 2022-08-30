#include "mbed.h"
#include "crazyflie.h"

// Define all LEDs as digital output objects
DigitalOut verm_dir(LED_RED_R,!false);
DigitalOut verde_dir(LED_GREEN_R, !false);
DigitalOut azul_esq(LED_BLUE_L, !false);
DigitalOut verm_esq(LED_RED_L, !false);
DigitalOut verde_esq(LED_GREEN_L, !false);
float i=0;
// Define all motors as PWM objects
PwmOut motor1(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);

// Main program
int main()
{
    // Blink blue LED indicating inicialization (5 seconds)
    while(i<5) 
    {
        azul_esq = !azul_esq;
        wait(0.5);
        i+=0.5;
    }

    // Turn on red LEDs indicating motors are armed
    verm_dir=!verm_dir;
    verm_esq=!verm_esq;

    // Test all motors with different frequencies (to make different noises)


    // Turn off red LEDs indicating motors are disarmed
    
    // Blink green LEDs indicating end of program
    while(true)
    {
        
    }
}
