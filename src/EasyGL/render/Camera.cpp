#include "Camera.h"

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
    m_View=m_View*m;
}