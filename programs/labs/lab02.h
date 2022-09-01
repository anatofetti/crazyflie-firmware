#include "mbed.h"
#include "crazyflie.h"

PwmOut motor(MOTOR1);

float control_motor(float omega)
{
    return a2*omega*omega + a1*omega;
}

int main()
{
    motor.period(1.0/500.0);
    motor=control_motor(1000.0);
    wait(4);
    motor=0;
    while(true)
    {
    }
}
