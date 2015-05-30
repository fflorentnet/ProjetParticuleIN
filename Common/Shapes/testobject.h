#ifndef TESTOBJECT_H
#define TESTOBJECT_H

#include "Object3D.h"

class TestObject : public Object3D
{
public:
    TestObject();
    void draw();

protected:
    void drawShape();

protected:
    GLfloat m_TabVertices[6*3];
};

#endif // TESTOBJECT_H
