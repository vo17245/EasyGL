#include <Eigen/Core>


class Math
{
public:
    static Eigen::Matrix4f Scale(float x,float y,float z);
    static Eigen::Matrix4f Translate(float x,float y,float z);
};