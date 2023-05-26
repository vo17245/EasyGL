#include "Math.h"

Eigen::Matrix4f Math::Scale(float x,float y,float z)
{
    Eigen::Matrix4f mat;
    mat<<x,0.0,0.0,0.0,
        0.0,y,0.0,0.0,
        0.0,0.0,z,0.0,
        0.0,0.0,0.0,1.0;
    return mat;
}


Eigen::Matrix4f Math::Translate(float x,float y,float z)
{
    Eigen::Matrix4f mat;
    mat<<1.0,0.0,0.0,x,
    0.0,1.0,0.0,y,
    0.0,0.0,1.0,z,
    0.0,0.0,0.0,1.0;
    return mat;
}