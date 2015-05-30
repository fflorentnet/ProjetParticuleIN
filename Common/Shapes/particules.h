#ifndef PARTICULES_H
#define PARTICULES_H

#include "Object3D.h"

class Particules : public Object3D
{
public:
    Particules();
    void draw();
    void update();

protected:
    void drawShape();

private:
    float life;
};

#endif // PARTICULES_H
