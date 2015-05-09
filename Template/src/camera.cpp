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
   Quaternion Px = Quaternion();
   Px.set(0,1,0,0);
   Quaternion Q = m_Orientation * Px * m_Orientation.conjuguate();

   m_Position.x = Q.getAX() * shift;
   m_Position.y = Q.getAY() * shift;
   m_Position.z = Q.getAZ() * shift;

//   m_Position += (qR(0 1 0 0)qR*).xyz * shift
}

void Camera::translateY(float shift)
{

}
void Camera::translateZ(float shift)
{

}
