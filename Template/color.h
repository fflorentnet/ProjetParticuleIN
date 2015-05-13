#ifndef COLOR_H
#define COLOR_H


class Color
{
public:
    int r;
    int g;
    int b;
    Color(): r(0), g(0), b(0) {}
    Color(int R, int G, int B): r(R), g(G), b(B) {}
    float getfR() { return r/255; }
    float getfG() { return g/255; }
    float getfB() { return b/255; }

    ~Color();
};

#endif // COLOR_H
