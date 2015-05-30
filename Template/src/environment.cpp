#include "environment.h"
#include "phenomene.h"

Environment::Environment()
{
     phenomenesContainer = (Phenomene*) malloc(MAX_PHENOMENE * sizeof(Phenomene));
}

void createPhenomene(int typePhenomene, float startTime){



}

void update(float delta){

    for(int i=0; i<MAX_PHENOMENE; i++){

        //Phenomene& p = phenomenesContainer[i]; // shortcut

        /*if(p.life > 0.0f){
            p.life -= delta;
            if (p.life > 0.0f){
                p.update(delta);
            }else{
                // destroy the phenomene
            }

        }*/
    }

}


Environment::~Environment()
{

}

