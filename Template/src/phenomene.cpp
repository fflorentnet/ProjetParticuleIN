#include "phenomene.h"



int Phenomene::findUnusedParticule()
{
    for(int i=lastParticule; i<MAX_PARTICULES; i++){
        if (p_Container[i].getLife() < 0){
            lastParticule = i;
            return i;
        }
    }
    for(int i=0; i<lastParticule; i++){
        if (p_Container[i].life < 0){
            lastParticule = i;
            return i;
        }
    }
    return 0;
}
