#ifndef EXPLOSION_H
#define EXPLOSION_H
#include "phenomene.h"

#define NB_PARTICULES 500

class Explosion : public Phenomene
{
public:
    Explosion(GLfloat* pos);
    Explosion();
    void draw();
    void update();

protected:
    void init();
    void drawShape();
    GLfloat m_tabSpeed[NB_PARTICULES*3];
    GLfloat m_Weight[NB_PARTICULES];
    GLfloat colorParticles[3] = {
        0.0f, 0.0f, 0.0f
    };


};

#endif // EXPLOSION_H
