#include "phenomene.h"
#include <cstdlib>


Phenomene::Phenomene()
{
}
    void
    Phenomene::setPosition(float x, float y, float z)
    {
        position[0] = x;
        position[1] = y;
        position[2] = z;
    }

    void
    Phenomene::setRandPositionOnTheFloor()
    {
        position[0] = RandomFloat(0.0f,10.0f);
        position[1] = 0.0f;
        position[2] = 0.0f;
    }

    bool
    Phenomene::isEnded()
    {
        return deathTime >= life;
    }

    float
    Phenomene::RandomFloat(float a, float b) {
        float random = ((float) rand()) / (float) RAND_MAX;
        float diff = b - a;
        float r = random * diff;
        return a + r;
    }
