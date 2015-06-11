#ifndef GRAPHICSENGINE_H
#define GRAPHICSENGINE_H

#include "GlWindow.h"


class GraphicsEngine : public GlWindow
{
    public:
        GraphicsEngine();
        ~GraphicsEngine();

        /*!
        *\brief Initialization des objets.
        */
        bool initializeObjects();

        void mousePressEvent(QMouseEvent *event);
        void mouseMoveEvent(QMouseEvent *event);
        void wheelEvent(QWheelEvent *event);

        void rotateBy(int x, int y, int z);

        /*!
        *\brief Rendu de la scène.
        */
        void render();

        void keyPressEvent(QKeyEvent *);
};


#endif // GRAPHICSENGINE_H

