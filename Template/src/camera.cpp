#include "camera.h"
#include "Vectors.h"
#include "AbstractFramework.h"
#include "quaternion.h"
Camera::Camera()
{
    position = Vec3(0,0,0);
}

Camera::~Camera()
{

}

void Camera::translate(float x, float y, float z)
{
    position.x += x;
    position.y += y;
    position.z += z;
}

void Camera::translateX(float shift)
{
   Quaternion q = Quaternion();
//   m_Position
}

void Camera::translateY(float shift)
{

}
void Camera::translateZ(float shift)
{

}
