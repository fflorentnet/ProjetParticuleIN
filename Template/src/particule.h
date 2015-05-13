#ifndef PARTICULE_H
#define PARTICULE_H

#include "Vectors.h"
#include "GlFramework.h"
#include "color.h"

class Particule
{
private:
    Vec3 Position;
    Vec3 Velocity;
    float life;
    Color col;
public:
    Particule();
    virtual ~Particule() = 0;
    float getLife() { return life; }
};

#endif // PARTICULE_H
