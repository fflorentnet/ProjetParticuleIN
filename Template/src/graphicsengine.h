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

        /*!
        *\brief Rendu de la scène.
        */
        void render();

        void keyPressEvent(QKeyEvent *);
};


#endif // GRAPHICSENGINE_H

