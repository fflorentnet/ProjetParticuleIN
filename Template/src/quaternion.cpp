#include "quaternion.h"
#include <stdlib.h>
#include <iostream>
Quaternion::~Quaternion()
{

}
/* void setFromAxis(float angle, float ax, float ay, float az);
    void setRotationMatrix (float* mat);*/
Quaternion Quaternion::operator+(const Quaternion& q)
{
    Quaternion qres(this->w+q.w, this->x+q.x, this->y+q.y, this->z+q.z);
    return qres;
}
 float Quaternion::dot(const Quaternion& q) const
{
    float qx = q.x;
    float qy = q.y;
    float qz = q.z;
    float qw = q.w;

    return qx*x + qy*y + qz*z + qw*w;
}

Vec3& Quaternion::operator*(const Vec3& v)
{
    Quaternion u = Quaternion(0,v.x, v.y, v.z);
    Quaternion temp;
    Vec3 res;
    temp = (*this) * u;
    temp *= this->conjuguate();
    res.x = temp.x;
    res.y = temp.y;
    res.z = temp.z;
    return res;
}
Quaternion Quaternion::operator*(const Quaternion& q)
{
    Quaternion qres = Quaternion();
    float qx = q.x;
    float qy = q.y;
    float qz = q.z;
    float qw = q.w;

    float qrw = w*qw -  x*qx - y*qy -z*qz;
    float qrx  = w*qx +x*qw +y*qz - z*qy;
    float qry  = w*qy - x*qz + y*qw +z*qx;
    float qrz =  w*qz + x*qw - y*qz + z*qy;
    qres.set(qrw, qrx, qry, qrz);
    qres.normalize();
    return qres;
}

Quaternion& Quaternion::operator*=(const Quaternion& q)
{
    float qx = q.x;
    float qy = q.y;
    float qz = q.z;
    float qw = q.w;

    w= w*qw -  x*qx - y*qy -z*qz;
    x= w*qx +x*qw +y*qz - z*qy;
    y= w*qy - x*qz + y*qw +z*qx;
    z=  w*qz + x*qw - y*qz + z*qy;
    this->normalize();
    return *this;
}

void Quaternion::set(float qw, float qx, float qy, float qz)
{
    w=qw;
    x=qx;
    y=qy;
    z=qz;
}
Quaternion Quaternion ::conjuguate()
{
    return Quaternion(w, -x, -y, -z);
}

void Quaternion::afficher()
{
    std::cout << "w:" << w << ",x:" << x << ",y:" << y << ",z:" << z << std::endl;
}

Quaternion Quaternion::operator*(float f)
{
    Quaternion q(f*w, f*x, f*y, f*z);
    return q;
}
void Quaternion::normalize()
{
    float norme = this->norm();
    this->set(w/norme, x/norme, y/norme, z/norme);
}

float Quaternion::norm()
{
    return sqrt(w*w + x*x + y*y + z*z);
}
Quaternion Quaternion::slerp(const Quaternion& q1,const Quaternion& q2,float t)
{
    Quaternion qr;
    float dotproduct = q1.dot(q2);
    float theta, st, sut, sout, coeff1, coeff2;

    t=t/2.0;

    theta = (float) acos(dotproduct);
    if (theta<0.0) theta=-theta;

    st = (float) sin(theta);
    sut = (float) sin(t*theta);
    sout = (float) sin((1-t)*theta);
    coeff1 = sout/st;
    coeff2 = sut/st;

    qr.x = coeff1*q1.x + coeff2*q2.x;
    qr.y = coeff1*q1.y + coeff2*q2.y;
    qr.z = coeff1*q1.z + coeff2*q2.z;
    qr.w = coeff1*q1.w + coeff2*q2.w;

    qr.normalize();
    return qr;
}
