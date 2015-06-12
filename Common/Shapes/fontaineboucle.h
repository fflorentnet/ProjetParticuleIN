#ifndef FONTAINEBOUCLE_H
#define FONTAINEBOUCLE_H
#include "Object3D.h"
#include "explosion.h"
#define NB_PARTICULES_FONTAINE_BOUCLE 500

class FontaineBoucle : public Object3D
{
public:
    FontaineBoucle();
    void draw();
    void update();
    void setPosition(float x, float y, float z);
protected:
    void init();
    void drawShape();
    float RandomFloat(float a, float b);
    float life = 0.0f;
    GLfloat position[3] = {
        0.0f, 0.0f, 0.0f
    };

    GLfloat m_tabSpeed[NB_PARTICULES_FONTAINE_BOUCLE*3];
    GLfloat m_Weight[NB_PARTICULES_FONTAINE_BOUCLE];
    GLfloat m_lives[NB_PARTICULES_FONTAINE_BOUCLE];

    GLfloat colorParticles[3] = {
        0.0f, 0.0f, 0.0f
    };
};

#endif // FONTAINEBOUCLE_H
