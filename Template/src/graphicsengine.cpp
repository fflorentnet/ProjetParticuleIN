#include "graphicsengine.h"


#include "Shapes/Basis.h"
#include "Shapes/TestObject.h"
#include "Shapes/particules.h"
#include "Shapes/explosion.h"
#include "environment.h"

#include <iostream>

using namespace std;


GLfloat angle1 = 0.0f;
GLfloat angle2 = 0.0f;

const GLfloat g_AngleSpeed = 10.0f;


Basis* g_Basis;
TestObject* test;

Explosion* explosion;
Explosion* explosionBis;
Environment* environnement;




GraphicsEngine::GraphicsEngine()
{
    setWindowTitle(trUtf8("IN55-GraphicsEngine"));

    g_Basis = new Basis( 10.0 );
    test = new TestObject();
    explosion = new Explosion();
    explosionBis = new Explosion();
    explosionBis->setPosition(0,0.5f,0);
    environnement = new Environment();
}


GraphicsEngine::~GraphicsEngine()
{
    delete g_Basis;
}


bool
GraphicsEngine::initializeObjects()
{
    // Fond noir
    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
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
        cout << "Loaded!" << endl;
    }
    else
    {
        cout << "NOT Loaded!" << endl;
    }
    createShader( "Shaders/particules" );
    cout << "Shader particules: ";
    if (useShader( "particules" ))
    {
        cout << "Loaded!" << endl;
    }
    else
    {
        cout << "NOT Loaded!" << endl;
    }

    createShader( "Shaders/explosion" );

    cout << "Shader explosion: ";
    if (useShader( "explosion" ))
    {
        cout << "Loaded!" << endl;
    }
    else
    {
        cout << "NOT Loaded!" << endl;
    }


    return true;
}


void
GraphicsEngine::render()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();//load identity matrix
    lookAt( 0, 5, 60, 0, 0, 0 );
    // Rendu des objets
    pushMatrix();
        rotate( angle1, 0, 1, 0 );
        rotate( angle2, 1, 0, 0 );
        explosion->update();
        explosion->draw();
        pushMatrix();
            explosionBis->update();
            explosionBis->draw();
        popMatrix();
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
