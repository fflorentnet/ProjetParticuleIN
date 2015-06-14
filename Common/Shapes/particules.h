#ifndef PARTICULES_H
#define PARTICULES_H

#include "phenomene.h"

#define POINTS 21
#define NB_PARTICULES 50

class Particules : public Phenomene
{
public:
    Particules();
    void draw();
    void update();

protected:
    void drawShape();
    GLfloat m_tabVertices[NB_PARTICULES*POINTS];
    GLfloat m_tabColors[NB_PARTICULES*POINTS];
    GLfloat m_tabLives[NB_PARTICULES*7];

};

#endif // PARTICULES_H
