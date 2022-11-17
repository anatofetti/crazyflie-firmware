# include "horizontal_estimator.h"

// Class constructor
HorizontalEstimator :: HorizontalEstimator () : flow (PA_7 ,PA_6 ,PA_5 , PB_4 )
{
    x=0;
    y=0;
    u=0;
    v=0;
}

// Initialize class
void HorizontalEstimator :: init ()
{
    flow.init();
}

// Predict vertical position and velocity from model
void HorizontalEstimator :: predict ( float phi , float theta )
{
    x += u*dt;
    y += v*dt;
    u += g*theta*dt;
    v -= g*phi*dt;
}

// Correct vertical position and velocity with measurement
void HorizontalEstimator :: correct ( float phi , float theta , float p, float q, float z)
{
     float den = cos ( phi )* cos ( theta ) ;
    if ( den > 0.5)
    {
        float d = z/ den;
        flow.read() ;
        float u_m = (sigma*flow.px+q)*d;
        float v_m = (sigma*flow.py-p)*d;
        u += wc_flow*dt*(u_m-u);
        v += wc_flow*dt*(v_m-v);
    }
}