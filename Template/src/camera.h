#ifndef CAMERA_H
#define CAMERA_H

#include "Vectors.h"
#include "GlFramework.h"
#include "quaternion.h"

class Camera
{
private:
    Vec3 m_Position;
    Quaternion m_Orientation;
    GLMatrix m_ViewMatrix;
    GLMatrix m_ProjectionMatrix;
public:
    Camera();
    ~Camera();
    void translate(float x, float y, float z);
    void translateX(float shift);
    void translateY(float shift);
    void translateZ(float shift);

    void rotate(float ax, float ay, float az);
    void rotateX(float angle);
    void rotateY(float angle);
    void rotateZ(float angle);
/*
    GLMatrix& getViewMatrix() const;
    void setAspectRatio(float ar);
    void setPlanes(float np, float fp);
    void setFOV(float angle);
    GLMatrix& getProjectionMatrix() const;
*/
    //void buildViewMatrix();
    //void buildProjectionMatrix();
};

#endif // CAMERA_H
