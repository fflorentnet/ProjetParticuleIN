#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#define MAX_PHENOMENE 50
#include "phenomene.h"

class Environment
{
public:
    Phenomene* phenomenesContainer[MAX_PHENOMENE];
    Environment();
    ~Environment();
    void createPhenomene(int typePhenomene, float startTime);
};

#endif // ENVIRONMENT_H
