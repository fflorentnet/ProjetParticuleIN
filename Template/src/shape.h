#ifndef SHAPE_H
#define SHAPE_H

#include "AbstractFramework.h"

class Shape
{
public:
    virtual Shape() = 0;
    virtual ~Shape();
    virtual int getSize() = 0;
    virtual GLfloat* getVertices() = 0;
    virtual GLfloat* getIndices() = 0;
};

#endif // SHAPE_H
