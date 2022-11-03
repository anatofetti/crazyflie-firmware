#ifndef parameters_h
#define parameters_h

#include <cmath>

// Physical constants
const float pi = 3.1416;
const float g = 9.81;       // m/s^2

// Quadcopter dimensions
const float m = 30.0e-3;    // kg
const float I_xx = 16.0e-6; // kg.m^2
const float I_yy = 16.0e-6; // kg.m^2
const float I_zz = 29.0e-6; // kg.m^2
const float l = 33.0e-3;    // m

// curva do sinal PWM (y) x velociade angular omega (x)
const float a2 = 1.226e-7;
const float a1 = 1.754e-14;

// curva da força de sustentação Fl(y) x velocidade angular omega (x)
const float kl = 1.59e-08;

// curva do angulo de guinagem psi(y) x tempo t(x)
const float kd = 1.489e-10;

// Estimador de atitude (Lab 7)
const float dt = 0.002;
const float wc = 1.0;
const float alpha = wc*dt/(1.0+wc*dt); 

// Controlador de atitude (Lab 8)
const float Ts_phi = 0.3; //segundos
const float OS_phi = 0.005; //0.5%
const float zeta_phi = abs(log(OS_phi))/sqrt(log(OS_phi)*log(OS_phi)+pi*pi);
const float wn_phi = 4/zeta_phi/Ts_phi;
const float kp_phi = wn_phi*wn_phi;
const float kd_phi = 2*zeta_phi*wn_phi; 
const float kp_theta = kp_phi;
const float kd_theta = kd_phi;

const float Ts_psi = 0.6; //segundos
const float OS_psi = 0.005; //0.5%
const float zeta_psi = abs(log(OS_psi))/sqrt(log(OS_psi)*log(OS_psi)+pi*pi);
const float wn_psi = 4/zeta_psi/Ts_psi;
const float kp_psi = wn_psi*wn_psi ; //mudar?
const float kd_psi = 2*zeta_psi*wn_psi ;  //mudar? 

// Lab 09
const float dt_range = 0.05; //50ms

#endif