#include "phenomene.h"
#include "fountainphenomene.h"
#include <stdlib.h>
#include "fountainparticule.h"

FountainPhenomene::FountainPhenomene()
{
    p_Container = (FountainParticule*) malloc(MAX_PARTICULES * sizeof(FountainParticule));
    origin = Vec3(0,0,0);
}

FountainPhenomene::~FountainPhenomene()
{

}

FountainPhenomene::FountainPhenomene(Vec3 Pos)
{
    p_Container = (FountainParticule*) malloc(MAX_PARTICULES * sizeof(FountainParticule));
    origin = Pos;
}

void FountainPhenomene::update()
{

}
