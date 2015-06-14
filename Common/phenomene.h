#ifndef PHENOMENE_H
#define PHENOMENE_H
#include "Object3D.h"

class Phenomene : public Object3D
{
public:
    Phenomene();
    virtual void update() = 0;
    virtual void draw() = 0;
    void setPosition(float x, float y, float z);
    void setRandPositionOnTheFloor();
    bool isEnded();

 protected:
    float RandomFloat(float, float);
    /*void init();
    void drawShape();*/
    virtual void init() = 0;
    virtual void drawShape() = 0;
    float life = 0.0f;
    float deathTime = 10.0f;
    GLfloat position[3] = {
        0.0f, 0.0f, 0.0f
    };

};

#endif // PHENOMENE_H
