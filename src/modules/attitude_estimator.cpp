# include "attitude_estimator.h"
#include <cmath>

// Class constructor
AttitudeEstimator :: AttitudeEstimator () : imu ( IMU_SDA , IMU_SCL )
{
phi = 0.0;
theta = 0.0;
psi = 0.0;
p = 0.0;
q = 0.0;
r = 0.0;
}

// Initialize class
void AttitudeEstimator :: init ()
{
imu.init();
}

// Estimate Euler angles (rad ) and angular velocities ( rad /s)
void AttitudeEstimator :: estimate ()

{
    imu.read();
    float phi_a = atan2(-imu.ay, -imu.az);
    phi = phi_a;
}