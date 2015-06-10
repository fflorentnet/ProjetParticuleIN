#ifndef EXPLOSION_H
#define EXPLOSION_H
#include "Object3D.h"

#define NB_PARTICULES 500

class Explosion : public Object3D
{
public:
    Explosion(GLfloat* pos);
    Explosion();
    void draw();
    void update();
    float RandomFloat(float, float);
    void setPosition(float x, float y, float z);
protected:
    void init();
    void drawShape();
    GLfloat m_tabSpeed[NB_PARTICULES*3];
    float life = 0.0f;
    GLfloat m_Weight[NB_PARTICULES];
    GLfloat position[3] = {
        0.0f, 0.0f, 0.0f
    };
    GLfloat colorParticles[3] = {
        0.0f, 0.0f, 0.0f
    };


};

#endif // EXPLOSION_H
