#ifndef FOUNTAINPHENOMENE_H
#define FOUNTAINPHENOMENE_H

#include "phenomene.h"
#include "Vectors.h"
#include "GlFramework.h"

class FountainPhenomene : public Phenomene
{
private:
public:
    FountainPhenomene();
    FountainPhenomene(Vec3 Pos);
    ~FountainPhenomene();
    void update(float delta);
};

#endif // FOUNTAINPHENOMENE_H
