#include "Camera.h"
#include <cmath>

Camera::Camera()
{
    m_View<<1.0,0.0,0.0,0.0,
    0.0,1.0,0.0,0.0,
    0.0,0.0,1.0,0.0,
    0.0,0.0,0.0,1.0;

}
Camera::Camera(const Eigen::Vector3<float>& position, Eigen::Vector3<float>& face)
{

}
Camera::~Camera()
{

}
Camera& Camera::operator=(const Camera& right)
{
    m_View=right.m_View;
    return *this;
}
void Camera::Move(float dx,float dy,float dz)
{
    Eigen::Matrix4<float> m;
    m<<1.0,0.0,0.0,-dx,
    0.0,1.0,0.0,-dy,
    0.0,0.0,1.0,-dz,
    0.0,0.0,0.0,1.0;
    m_View=m*m_View;
}

void Camera::SetPosition(float x,float y,float z)
{
    m_View<<1.0,0.0,0.0,-x,
    0.0,1.0,0.0,-y,
    0.0,0.0,1.0,-z,
    0.0,0.0,0.0,1.0;
}

void Camera::SetRotation(float angle)
{
    m_View<<cos(angle),-1*sin(angle),0.0,0.0,
    sin(angle),cos(angle),0.0,0.0,
    0.0,0.0,1.0,0.0,
    0.0,0.0,0.0,1.0;
}

void Camera::Rotate(float angle)
{
    Eigen::Matrix4<float> m;
    m<<cos(angle),-1*sin(angle),0.0,0.0,
    sin(angle),cos(angle),0.0,0.0,
    0.0,0.0,1.0,0.0,
    0.0,0.0,0.0,1.0;
    m_View=m*m_View;
}