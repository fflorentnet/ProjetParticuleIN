#ifndef FONTAINEBOUCLE_H
#define FONTAINEBOUCLE_H
#include "phenomene.h"
#include "explosion.h"
#define NB_PARTICULES_FONTAINE_BOUCLE 500

class FontaineBoucle : public Phenomene
{
public:
    FontaineBoucle();
    void draw();
    void update();
protected:
    void init();
    void drawShape();

    GLfloat m_tabSpeed[NB_PARTICULES_FONTAINE_BOUCLE*3];
    GLfloat m_Weight[NB_PARTICULES_FONTAINE_BOUCLE];
    GLfloat m_lives[NB_PARTICULES_FONTAINE_BOUCLE];

    GLfloat colorParticles[3] = {
        0.0f, 0.0f, 0.0f
    };
};

#endif // FONTAINEBOUCLE_H
