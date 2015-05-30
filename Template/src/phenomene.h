#ifndef PHENOMENE_H
#define PHENOMENE_H

#include "Vectors.h"
#include "GlFramework.h"
#include "particule.h"
#include "Shapes/Basis.h"
#define MAX_PARTICULES 3000

class Phenomene
{
public:
    char* shaderColor;
    char* shaderFrag;
    Particule* p_Container;
    Object3D *s;
    int lastParticule;
    Vec3 origin;
    float startTime;
    float life;
    int findUnusedParticule();

    Phenomene();
    Phenomene(Vec3 Pos);
    virtual ~Phenomene() = 0;
    virtual void update(float delta) = 0;

};

#endif // PHENOMENE_H
