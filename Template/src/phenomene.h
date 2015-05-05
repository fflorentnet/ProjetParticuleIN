#ifndef PHENOMENE_H
#define PHENOMENE_H


class Phenomene
{
private:
    char* shaderColor;
    char* shaderFrag;
public:
    virtual Phenomene();
    virtual ~Phenomene();
    virtual void update() = 0;
};

#endif // PHENOMENE_H
