#include "environment.h"

#include "Shapes/particules.h"
#include "Shapes/explosion.h"
#include "Shapes/fusee.h"
#include "Shapes/fontaine.h"
#include "Shapes/fontaineboucle.h"

#include <iostream>
using namespace std;

Environment::Environment()
{
    for(int i=0; i<MAX_PHENOMENE; i++)
        phenomenesContainer[i] = NULL;
}

void Environment::createPhenomene(int typePhenomene, float startTime){

    cout << "Nouveau phenomene ajouté : ";

    Phenomene* newPhenomene;
    switch(typePhenomene)
    {
        case 1:
            newPhenomene = new Fusee();
            newPhenomene->setPosition(0,0,0);
            cout << "Fusee ";
            break;
        case 2:
            newPhenomene = new Fontaine();
            newPhenomene->setPosition(-1.0,0.0,0);
            cout << "Fontaine ";
            break;
        case 3:
            newPhenomene = new FontaineBoucle();
            newPhenomene->setRandPositionOnTheFloor();
            cout << "FontaineBoucle ";
            break;
        case 4:
            newPhenomene = new Explosion();
            newPhenomene->setPosition(5.0,5.0,0);
            cout << "Explosion ";
            break;
    }

    Phenomene* tmpPhenomene;
    for(int i=0; i<MAX_PHENOMENE; i++){

        tmpPhenomene = phenomenesContainer[i];
        if(tmpPhenomene == NULL || tmpPhenomene->isEnded())
        {
            phenomenesContainer[i] = newPhenomene;
            cout << "en position " << i;
            break;
        }
    }


    cout << endl;
}


Environment::~Environment()
{

}

