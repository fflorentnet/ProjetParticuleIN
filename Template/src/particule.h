#ifndef PARTICULE_H
#define PARTICULE_H

#include "Vectors.h"
#include "GlFramework.h"
#include "color.h"
#include "shape.h"
class Particule
{
private:
    Vec3 Position;
    Vec3 Velocity;
    float lifeTime;
    Color col;
public:
    Particule();
    virtual ~Particule() = 0;
    float getLife() { return lifeTime; }
};

#endif // PARTICULE_H
