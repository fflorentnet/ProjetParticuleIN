#ifndef EXPLOSION_H
#define EXPLOSION_H
#include "Object3D.h"

#define POINTS 21
#define NB_PARTICULES 50

class Explosion : public Object3D
{
public:
    Explosion();
    void draw();
    void update();
    float RandomFloat(float, float);

protected:
    void drawShape();
    GLfloat m_tabSpeed[NB_PARTICULES*3];
    float life = 0.0f;
    GLfloat position[3] = {
        0.0f, 10.0f, 0.0f
    };
    GLfloat colorParticles[3] = {
        0.0f, 0.0f, 0.0f
    };


};

#endif // EXPLOSION_H
