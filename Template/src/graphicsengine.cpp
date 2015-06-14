#include "graphicsengine.h"


#include "Shapes/Basis.h"
#include "Shapes/TestObject.h"
#include "Shapes/particules.h"
#include "Shapes/explosion.h"
#include "Shapes/fusee.h"
#include "Shapes/fontaine.h"
#include "Shapes/fontaineboucle.h"
#include "environment.h"

#include <iostream>

using namespace std;


GLfloat angle1 = 0.0f;
GLfloat angle2 = 0.0f;


GLfloat pos_x = 0.0f;
GLfloat pos_y = 0.0f;

GLfloat zoom = 30.0f;


GLfloat x_rot = 0.0f;
GLfloat y_rot = 0.0f;
GLfloat z_rot = 0.0f;

QPoint last_pos;

const GLfloat g_AngleSpeed = 10.0f;


Basis* g_Basis;
TestObject* test;

Particules* particules;

Explosion* explosion;

Fusee* fusee;
Fusee* fusee2;
Fusee* fusee3;

Fontaine* fontaineSimple;

FontaineBoucle* fontaine;
FontaineBoucle* fontaine2;
FontaineBoucle* fontaine3;

Environment* environnement;




GraphicsEngine::GraphicsEngine()
{
    setWindowTitle(trUtf8("IN55-GraphicsEngine"));

    g_Basis = new Basis( 10.0 );
    test = new TestObject();
    /*particules = new Particules();
    explosion = new Explosion();*/

    environnement = new Environment();

    fusee = new Fusee();
    fusee2 = new Fusee();
    fusee3 = new Fusee();

    fontaineSimple = new Fontaine();
    fontaineSimple->setPosition(7.0f,10.0f, 0.0f);

    fontaine = new FontaineBoucle();
    fontaine2 = new FontaineBoucle();
    fontaine2->setPosition(5.0f,0.0f, 0.0f);
    fontaine3 = new FontaineBoucle();
    fontaine3->setPosition(10.0f,0.0f, 0.0f);
}


GraphicsEngine::~GraphicsEngine()
{
    delete g_Basis;
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
    lookAt( 0, 5, -zoom, 0, 0, 0 );
     //environnement->update(1.0);

    // Rendu des objets
    pushMatrix();
        rotate( angle1, 0, 1, 0 );
        rotate( angle2, 1, 0, 0 );
        /*rotate( x_rot, 1, 0, 0 );
        rotate( y_rot, 0, 1, 0 );
        rotate( z_rot, 0, 0, 1 );*/

        g_Basis->draw();
       /* test->draw();

        particules->update();
        particules->draw();*/

        /*explosion->update();
        explosion->draw();*/
/*
        fontaineSimple->update();
        fontaineSimple->draw();

        fusee->update();
        fusee->draw();

        fusee2->update();
        fusee2->draw();

        fusee3->update();
        fusee3->draw();

*/
       /* fontaine->update();
        fontaine->draw();

        fontaine2->update();
        fontaine2->draw();

        fontaine3->update();
        fontaine3->draw();*/

        for(int i=0; i<50; i++){

            Phenomene* p = environnement->phenomenesContainer[i];
            if(p == NULL)
            {
                //cout << "Break : " << i << endl;
                break;
            }

            //cout << i << " : " << p << endl;
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
        rotateBy(dy*8, 0, 0);
        rotateBy(0, dx*8, 0);
    }
    last_pos = event->pos();
}


void GraphicsEngine::rotateBy(int x, int y, int z)
{
    x_rot += x;
    y_rot += y;
    z_rot += z;
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
            pos_x -= g_AngleSpeed;
            break;

        case Qt::Key_Right:
            angle1 += g_AngleSpeed;
            pos_x += g_AngleSpeed;
            break;

        case Qt::Key_Up:
            angle2 -= g_AngleSpeed;
            pos_y -= g_AngleSpeed;
            break;

        case Qt::Key_Down:
            angle2 += g_AngleSpeed;
            pos_y += g_AngleSpeed;
            break;

        case Qt::Key_R:
            angle1 = angle2 = 0.0f;
            break;

        case Qt::Key_A:
            environnement->createPhenomene(1,0);
            break;
        case Qt::Key_B:
            environnement->createPhenomene(2,0);
            break;
        case Qt::Key_C:
            environnement->createPhenomene(3,0);
            break;
        case Qt::Key_D:
            environnement->createPhenomene(4,0);
            break;


    }
}
