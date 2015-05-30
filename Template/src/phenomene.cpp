#include "phenomene.h"

Phenomene::Phenomene()
{
    origin = Vec3(0,0,0);
}

Phenomene::Phenomene(Vec3 pos)
{
    origin = pos;
}

Phenomene::~Phenomene()
{

}

void Phenomene::update(float delta) {

}

int Phenomene::findUnusedParticule()
{
    for(int i=lastParticule; i<MAX_PARTICULES; i++){
        if (p_Container[i].getLife() < 0){
            lastParticule = i;
            return i;
        }
    }
    for(int i=0; i<lastParticule; i++){
        if (p_Container[i].getLife() < 0){
            lastParticule = i;
            return i;
        }
    }
    return 0;
}
