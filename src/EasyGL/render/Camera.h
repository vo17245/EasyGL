#include "Eigen/Core"

class Camera
{
private:
    Eigen::Matrix4<float> m_View;
public:
    
    Camera();
    Camera(const Eigen::Vector3<float>& position, Eigen::Vector3<float>& face);
    Camera(const Eigen::Matrix4<float>& view)
        :m_View(view){}
    ~Camera();
    Camera& operator=(const Camera& right);
    inline const Eigen::Matrix4<float>& GetView()const{return m_View;}
    void Move(float dx,float dy,float dz);
};