# include "mixer.h"

// Class constructor
Mixer :: Mixer () : motor_1 ( MOTOR1 ) , motor_2 ( MOTOR2 ) , motor_3 ( MOTOR3 ) , motor_4 ( MOTOR4 ), verm_dir(LED_RED_R,!false), verm_esq(LED_RED_L,!false), verde_dir(LED_GREEN_R,!false), verde_esq(LED_GREEN_L,!false), azul(LED_BLUE_L,!false)
{
    motor_1 . period (1.0/500.0) ;
    motor_2 . period (1.0/500.0) ;
    motor_3 . period (1.0/500.0) ;
    motor_4 . period (1.0/500.0) ;
    motor_1 = 0.0;
    motor_2 = 0.0;
    motor_3 = 0.0;
    motor_4 = 0.0;
}

// Actuate motors with desired total trust force (N) and torques (N.m)
void Mixer :: actuate ( float f_t , float tau_phi , float tau_theta , float tau_psi )
{
    if (armed) 
    {
        mixer (f_t , tau_phi , tau_theta , tau_psi );
        motor_1 = control_motor ( omega_1 ) ;
        motor_2 = control_motor ( omega_2 ) ;
        motor_3 = control_motor ( omega_3 ) ;
        motor_4 = control_motor ( omega_4 ) ;
    }
}

// Convert total trust force (N) and torques (N.m) to angular velocities ( rad /s)
void Mixer :: mixer ( float f_t , float tau_phi , float tau_theta , float tau_psi )
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

// Convert desired angular velocity ( rad /s) to PWM signal (%)
float Mixer :: control_motor ( float omega )
{
    return a2*omega*omega + a1*omega;
}

void Mixer :: arm()
{
    armed = true;
    verm_dir = false;
    verm_esq = false;
    verde_dir = true;
    verde_esq = true;
    wait(2);
}

void Mixer :: disarm()
{
    actuate(0, 0, 0, 0);
    armed = false;
    wait(2);
    verm_dir = true;
    verm_esq = true;
    verde_dir = false;
    verde_esq = false;
}
