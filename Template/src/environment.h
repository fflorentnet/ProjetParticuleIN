#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#define MAX_PHENOMENE 100
#include "phenomene.h"

class Environment
{
public:
    Phenomene* phenomenesContainer[MAX_PHENOMENE];
    Environment();
    ~Environment();
    void createPhenomene(int typePhenomene);
};

#endif // ENVIRONMENT_H
