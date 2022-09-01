#include "mbed.h"
#include "crazyflie.h"

PwmOut motor1(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);

float control_motor(float omega)
{
    return a2*omega*omega + a1*omega;
}
float i=1000;

int main()
{
    while(true) 
    {
        motor1 = control_motor(i);
        motor2 = control_motor(2*i);
        motor3 = control_motor(i);
        motor4 = control_motor(2*i);

        wait(2);

        motor1 = 0;
        motor2 = 0;
        motor3 = 0;
        motor4 = 0;

        wait(2);
        
    }
}
