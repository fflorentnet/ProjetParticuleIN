#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#define MAX_PHENOMENE 50
#include "phenomene.h"

class Environment
{
public:
    Phenomene* phenomenesContainer;
    Environment();
    ~Environment();
    void createPhenomene(int typePhenomene, float startTime);
    void update(float delta);
};

#endif // ENVIRONMENT_H
