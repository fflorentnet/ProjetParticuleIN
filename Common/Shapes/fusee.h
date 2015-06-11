#ifndef FUSEE_H
#define FUSEE_H
#include "Object3D.h"
#include "explosion.h"

class Fusee : public Object3D
{
public:
    Fusee();
    void draw();
    void update();
    void setPosition(float x, float y, float z);
protected:
    void init();
    void drawShape();
    float RandomFloat(float a, float b);
    Explosion* explosion;
    bool isExploded = false;
    float life = 0.0f;
    float explodeTime = 0.0f;
    GLfloat position[3] = {
        0.0f, 0.0f, 0.0f
    };
    GLfloat returnedPosition[3] = {
        0.0f, 0.0f, 0.0f
    };
    GLfloat speed[3] = {
        0.0f, 0.0f, 0.0f
    };
    GLfloat weight[1] = {
        0.0f
    };
    GLfloat colorParticles[3] = {
        0.0f, 0.0f, 0.0f
    };
};

#endif // FUSEE_H
