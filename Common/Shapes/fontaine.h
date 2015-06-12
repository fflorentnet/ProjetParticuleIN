#ifndef FONTAINE_H
#define FONTAINE_H
#include "Object3D.h"


#define NB_PARTICULES_FONTAINE 500

class Fontaine : public Object3D
{
public:
    Fontaine();
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

    GLfloat lives[NB_PARTICULES_FONTAINE];
    GLfloat m_tabSpeed[NB_PARTICULES_FONTAINE*3];
    GLfloat m_Weight[NB_PARTICULES_FONTAINE];
    GLfloat colorParticles[3] = {
        0.0f, 0.0f, 0.0f
    };
};

#endif // FONTAINE_H
