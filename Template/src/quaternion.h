#ifndef QUATERNION_H
#define QUATERNION_H
#include "Vectors.h"
#include "GlFramework.h"

class Quaternion
{
private:
    float x;
    float y;
    float z;
    float w;
    float norm();
public:
    Quaternion(): x(0), y(0), z(0), w(0) {}
    Quaternion(float ww, float xx, float yy, float zz): x(xx), y(yy), z(zz), w(ww) {}
    ~Quaternion();
    void afficher();
    Quaternion operator*(const Quaternion& q);
    Vec3& operator*(const Vec3& v);
    Quaternion operator*(float f);
    Quaternion operator+(const Quaternion& q);
    Quaternion& operator*=(const Quaternion& q);
    float dot(const Quaternion& q) const;
    void set(float w, float x, float y, float z);
    void setFromAxis(float angle, float ax, float ay, float az);
    Quaternion conjuguate();
    Quaternion slerp(const Quaternion& q1,const Quaternion& q2,float t);
    void normalize();
    void setRotationMatrix (float* mat);

    float getAA() { return x; }
    float getAY() { return y; }
    float getAZ() { return z; }

};

#endif // QUATERNION_H
