#ifndef FONTAINE_H
#define FONTAINE_H
#include "phenomene.h"


#define NB_PARTICULES_FONTAINE 500

class Fontaine : public Phenomene
{
public:
    Fontaine();
    void draw();
    void update();
protected:
    void init();
    void drawShape();

    GLfloat lives[NB_PARTICULES_FONTAINE];
    GLfloat m_tabSpeed[NB_PARTICULES_FONTAINE*3];
    GLfloat m_Weight[NB_PARTICULES_FONTAINE];
    GLfloat colorParticles[3] = {
        0.0f, 0.0f, 0.0f
    };
};

#endif // FONTAINE_H
