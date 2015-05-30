#include "graphicsengine.h"


#include "Shapes/Basis.h"
#include "Shapes/TestObject.h"
#include "environment.h"

#include <iostream>

using namespace std;


GLfloat angle1 = 30.0f;
GLfloat angle2 = 20.0f;

const GLfloat g_AngleSpeed = 10.0f;


Basis* g_Basis;
TestObject* test;

Environment* environnement;




GraphicsEngine::GraphicsEngine()
{
    setWindowTitle(trUtf8("IN55-GraphicsEngine"));

    g_Basis = new Basis( 10.0 );
    test = new TestObject();
    environnement = new Environment();
}


GraphicsEngine::~GraphicsEngine()
{
    delete g_Basis;
}


bool
GraphicsEngine::initializeObjects()
{
    // Fond gris
    glClearColor( 0.2f, 0.2f, 0.2f, 1.0f );
    glEnable( GL_DEPTH_TEST );

    // Chargement des shaders
    createShader( "Shaders/color" );

    cout << "Shader color: ";
    if (useShader( "color" ))
    {
        cout << "Loaded!" << endl;
    }
    else
    {
        cout << "NOT Loaded!" << endl;
    }


    createShader( "Shaders/test" );

    cout << "Shader test: ";
    if (useShader( "test" ))
    {
        cout << "test Loaded!" << endl;
    }
    else
    {
        cout << "test NOT Loaded!" << endl;
    }




    return true;
}


void
GraphicsEngine::render()
{
    // Initialisation de la caméra
    lookAt( 0, 5, 30, 0, 0, 0 );

     //environnement->update(1.0);

    // Rendu des objets
    pushMatrix();
        rotate( angle1, 0, 1, 0 );
        rotate( angle2, 1, 0, 0 );

        g_Basis->draw();
        test->draw();
    popMatrix();


}


void
GraphicsEngine::keyPressEvent( QKeyEvent* event )
{
    switch( event->key())
    {
        case Qt::Key_Escape:
            close();
            break;

        case Qt::Key_Left:
            angle1 -= g_AngleSpeed;
            break;

        case Qt::Key_Right:
            angle1 += g_AngleSpeed;
            break;

        case Qt::Key_Up:
            angle2 -= g_AngleSpeed;
            break;

        case Qt::Key_Down:
            angle2 += g_AngleSpeed;
            break;

        case Qt::Key_R:
            angle1 = angle2 = 0.0f;
            break;
    }
}
