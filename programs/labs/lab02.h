#include "mbed.h"
#include "crazyflie.h"

PwmOut motor(MOTOR1);

float control_motor(float omega)
{
    return a2*omega*omega + a1*omega;

}

float i=0.1;
int main()
{
    while(true) 
    {
        if (i<1.05)
        {
            motor = i;
            wait(6);
            motor = 0.0;
            wait(12);
            i+=0.1;
        }
        else 
        {
            i=0.1;
        }
        
    }
}
