#include "camera.h"
#include "Vectors.h"
#include "AbstractFramework.h"
#include "quaternion.h"

Camera::Camera()
{
    m_Position = Vec3(0,0,0);
}
Camera::Camera(int x, int y, int z,
               int lX, int lY, int lZ)
{
    m_Position = Vec3(x,y,z);
    m_Look = Vec3(lX, lY, lZ);
}

Camera::~Camera()
{

}
float deltaAngle = 0.0f;
void Camera::translate(float x, float y, float z)
{
    m_Position.x += x;
    m_Position.y += y;
    m_Position.z += z;
}
void Camera::translateLook(float x, float y, float z){

    // update camera's direction
    m_Look.x += x;
    m_Look.y += y;
    m_Look.z += z;
}

void Camera::translateX(float shift)
{
   Quaternion Px = Quaternion();
   Px.set(0,1,0,0);
   Quaternion Q = m_Orientation * Px * m_Orientation.conjuguate();

   m_Position.x = Q.getAX() * shift;
   m_Position.y = Q.getAY() * shift;
   m_Position.z = Q.getAZ() * shift;
}

void Camera::translateY(float shift)
{

}
void Camera::translateZ(float shift)
{

}
