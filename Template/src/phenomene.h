#ifndef PHENOMENE_H
#define PHENOMENE_H

#include "Vectors.h"
#include "GlFramework.h"
#include "particule.h"

#define MAX_PARTICULES 3000

class Phenomene
{
private:
    char* shaderColor;
    char* shaderFrag;
    Particule* p_Container;
    Shape *s;
    int lastParticule;
    Vec3 origin;
    int findUnusedParticule();
public:
    virtual Phenomene();
    virtual Phenomene(Vec3 Pos);
    virtual ~Phenomene();
    virtual void update() = 0;

};

#endif // PHENOMENE_H
