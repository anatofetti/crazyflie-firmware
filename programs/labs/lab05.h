# include "mbed.h"
# include "crazyflie.h"

// Define all motors as PWM objects
PwmOut motor_1 ( MOTOR1 );
PwmOut motor_2 ( MOTOR2 );
PwmOut motor_3 ( MOTOR3 );
PwmOut motor_4 ( MOTOR4 );

// Define angular velocities (rad/s)
float omega_1 ;
float omega_2 ;
float omega_3 ;
float omega_4 ;

// Converts desired angular velocity (rad/s) to PWM signal (%)
float control_motor ( float omega )
{
    return a2*omega*omega + a1*omega;
}

// Converts total trust force (N) and torques (N.m) to angular velocities (rad/s)
void mixer ( float f_t , float tau_phi , float tau_theta , float tau_psi )
{
    float omega1_qdrd = ( + 1/(4*kl)*f_t - 1/(4*kl*l)*tau_phi - 1/(4*kl*l)*tau_theta - 1/(4*kd*l)*tau_psi);
    float omega2_qdrd = ( + 1/(4*kl)*f_t - 1/(4*kl*l)*tau_phi + 1/(4*kl*l)*tau_theta + 1/(4*kd*l)*tau_psi);
    float omega3_qdrd = ( + 1/(4*kl)*f_t + 1/(4*kl*l)*tau_phi + 1/(4*kl*l)*tau_theta - 1/(4*kd*l)*tau_psi);
    float omega4_qdrd = ( + 1/(4*kl)*f_t + 1/(4*kl*l)*tau_phi - 1/(4*kl*l)*tau_theta + 1/(4*kd*l)*tau_psi);
    if (omega1_qdrd>0) {omega_1 = sqrt(omega1_qdrd);}
    else {omega_1 = 0;}
    if (omega2_qdrd>0) {omega_2 = sqrt(omega2_qdrd);}
    else {omega_2 = 0;}
    if (omega3_qdrd>0) {omega_3 = sqrt(omega3_qdrd);}
    else {omega_3 = 0;}
    if (omega4_qdrd>0) {omega_4 = sqrt(omega4_qdrd);}
    else {omega_4 = 0;}
}

// Actuate motors with desired total trust force (N) and torques (N.m)
void actuate ( float f_t , float tau_phi , float tau_theta , float tau_psi )
{
    mixer (f_t , tau_phi , tau_theta , tau_psi );
    motor_1 = control_motor ( omega_1 ) ;
    motor_2 = control_motor ( omega_2 ) ;
    motor_3 = control_motor ( omega_3 ) ;
    motor_4 = control_motor ( omega_4 ) ;
}

// Main program
int main ()
{
    // Set all PWM frequencies to 500 Hz
    motor_1 . period (1.0/500.0) ;
    motor_2 . period (1.0/500.0) ;
    motor_3 . period (1.0/500.0) ;
    motor_4 . period (1.0/500.0) ;
    // Actuate motor with 70% mg total thrust force (N) and zero torques (N.m)
    actuate (0 ,0 ,0 ,-0.001) ;
    wait (5) ;
    // Turn off all motors
    actuate (0 ,0 ,0 ,0) ;
    // End of program
    while ( true )
    {
    }
}
