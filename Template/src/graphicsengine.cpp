#include "graphicsengine.h"


#include "Shapes/Basis.h"
#include "environment.h"
#include "camera.h"
#include <iostream>

using namespace std;


GLfloat angle1 = 0.0f;
GLfloat angle2 = 0.0f;

GLfloat zoom = 30.0f;

float angle = 0;
QPoint last_pos;

const GLfloat g_AngleSpeed = 10.0f;

Camera* g_Camera;
Basis* g_Basis;
Environment* environnement;

GraphicsEngine::GraphicsEngine()
{
    setWindowTitle(trUtf8("IN55-GraphicsEngine"));

    g_Basis = new Basis( 10.0 );
    g_Camera = new Camera(0,-5,30
                         ,0,0,0);
    environnement = new Environment();

}


GraphicsEngine::~GraphicsEngine()
{
    delete g_Basis;
    delete environnement;
    delete g_Camera;
}

void GraphicsEngine::wheelEvent(QWheelEvent *event)
{
    zoom *= 1.0 + (1.0 * event->delta() / 1200.0);
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


    createShader( "Shaders/simpleMovement" );

    cout << "Shader simpleMovement: ";
    if (useShader( "simpleMovement" ))
    {
        cout << "Loaded!" << endl;
    }
    else
    {
        cout << "NOT Loaded!" << endl;
    }

    createShader( "Shaders/fountain" );

    cout << "Shader fountain: ";
    if (useShader( "fountain" ))
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
    // Initialisation de la caméra
    lookAt( g_Camera->getPosition().x , g_Camera->getPosition().y, g_Camera->getPosition().z
            , g_Camera->getLook().x, g_Camera->getLook().y, g_Camera->getLook().z);

    // Rendu des objets
    pushMatrix();
        rotate( angle1, 0, 1, 0 );
        rotate( angle2, 1, 0, 0 );

        g_Basis->draw();
        for(int i=0; i<100; i++){

            Phenomene* p = environnement->phenomenesContainer[i];
            if(p == NULL)
            {
                break;
            }
            p->update();
            p->draw();
        }

    popMatrix();


}

void GraphicsEngine::mousePressEvent(QMouseEvent *event)
{
    last_pos = event->pos();
}

void GraphicsEngine::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - last_pos.x();
    int dy = event->y() - last_pos.y();

    if (event->buttons() & Qt::RightButton)
    {
       g_Camera->translateLook(dx/2,
                            dy/2,
                            0
                            );
    }
    last_pos = event->pos();
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
    case Qt::Key_8:
        g_Camera->translate(0,1,0);
        g_Camera->translateLook(0,1,0);
            break;

    case Qt::Key_2:
        g_Camera->translate(0,-1,0);
        g_Camera->translateLook(0,-1,0);
            break;

    case Qt::Key_4:
        g_Camera->translate(-1,0,0);
        g_Camera->translateLook(-1,0,0);
            break;
    case Qt::Key_6:
        g_Camera->translate(1,0,0);
        g_Camera->translateLook(1,0,0);
            break;
    case Qt::Key_Minus:
        g_Camera->translate(0,0,-1);
        break;
    case Qt::Key_Plus:
        g_Camera->translate(0,0,1);
        break;


        case Qt::Key_R:
            angle1 = angle2 = 0.0f;
            break;
}
    switch( event->key())
    {

        case Qt::Key_A:
            environnement->createPhenomene(1);
            break;
        case Qt::Key_B:
            environnement->createPhenomene(2);
            break;
        case Qt::Key_C:
            environnement->createPhenomene(3);
            break;
        case Qt::Key_D:
            environnement->createPhenomene(4);
            break;
        case Qt::Key_E:
            environnement->createPhenomene(5);
            break;

    }
}
