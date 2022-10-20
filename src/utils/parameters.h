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

const float dt = 0.002;
const float wc = 10;
const float alpha = wc*dt/(1+wc*dt); 
#endif