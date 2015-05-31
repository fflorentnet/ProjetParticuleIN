#ifndef PARTICULES_H
#define PARTICULES_H

#include "Object3D.h"

#define POINTS 21
#define NB_PARTICULES 50

class Particules : public Object3D
{
public:
    Particules();
    void draw();
    void update();
    float RandomFloat(float, float);

protected:
    void drawShape();
    GLfloat m_tabVertices[NB_PARTICULES*POINTS];
    GLfloat m_tabColors[NB_PARTICULES*POINTS];
    GLfloat m_tabLives[NB_PARTICULES*7];

private:
    float life;

};

#endif // PARTICULES_H
