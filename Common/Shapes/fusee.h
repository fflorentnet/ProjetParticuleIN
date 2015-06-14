#ifndef FUSEE_H
#define FUSEE_H
#include "phenomene.h"
#include "explosion.h"

class Fusee : public Phenomene
{
public:
    Fusee();
    void draw();
    void update();

protected:
    void init();
    void drawShape();
    Explosion* explosion;
    bool isExploded = false;
    float explodeTime = 0.0f;

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
