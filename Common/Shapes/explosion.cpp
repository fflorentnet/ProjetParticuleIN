#include "explosion.h"
#include <math.h>
#include <cstdlib>
#include <iostream>

using namespace std;

#define PI 3.14159265


Explosion::Explosion()
{
    init();
}
void Explosion::setPosition(float x, float y, float z)
{
    position[0] = x;
    position[1] = y;
    position[2] = z;
}


void
Explosion::update()
{
    life+= 0.01f; // contient la vie de l'ensemble / du phenomene
    if(life > 1.0f)
    {

       setPosition(this->RandomFloat(-10,10),this->RandomFloat(-10,10), 0);
       init();
    }
}
void Explosion::init(){
    float velocity = 4.0f;
    float theta = (PI * 2)/NB_PARTICULES;
    life = 0.0f;
    float randVelocity = 0.0f;
    float particleAngle = 0.0f;

    for( GLuint i = 0; i < NB_PARTICULES * 3; i+=3 )
    {
        randVelocity = RandomFloat(1.0f,velocity*velocity);
        particleAngle = i*theta;
        m_tabSpeed[i+0] = cos(particleAngle)*randVelocity;
        m_tabSpeed[i+1] = sin(particleAngle)*randVelocity;
        m_tabSpeed[i+2] = 0;
    }
    for (GLuint i = 0; i <NB_PARTICULES ; i++)
        m_Weight[i] = RandomFloat(0.001f,1.2f);

    colorParticles[0] = RandomFloat(50,200);
    colorParticles[1] = RandomFloat(50,200);
    colorParticles[2] = RandomFloat(50,200);
 /*   colorParticles[0] = 255.0f;
    colorParticles[1] = 0.0f;
    colorParticles[2] = 0.0f;*/

}
void
Explosion::draw()
{
    if (m_Framework->useShader( "explosion" ))
    {
        m_Framework->computeAncillaryMatrices();
        GLint var_id = glGetUniformLocation( m_Framework->getCurrentShaderId(), "MVP" );
        m_Framework->transmitMVP( var_id );

        drawShape();
    }
}

float
Explosion::RandomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

void
Explosion::drawShape()
{

    glEnable( GL_POINT_SMOOTH );
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    GLint var1 = glGetUniformLocation( m_Framework->getCurrentShaderId(), "life" );
    glUniform1f(var1, life);
    GLint var2 = glGetUniformLocation( m_Framework->getCurrentShaderId(), "position" );
    glUniform3f(var2, position[0], position[1], position[2]);
    GLint var3 = glGetUniformLocation( m_Framework->getCurrentShaderId(), "colorParticles" );
    glUniform3f(var3, colorParticles[0]/255, colorParticles[1]/255, colorParticles[2]/255);
    GLint var4 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "velocity" );
    glEnableVertexAttribArray( var4 );
    glVertexAttribPointer( var4, 3, GL_FLOAT, GL_FALSE, 0, m_tabSpeed );

    GLint var5 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "poids" );
    glEnableVertexAttribArray( var5 );
    glVertexAttribPointer( var5, 1, GL_FLOAT, GL_FALSE, 0, m_Weight);

    glPointSize(1);
    glDrawArrays( GL_POINTS, 0, NB_PARTICULES );

    glDisableVertexAttribArray( var1 );
    glDisableVertexAttribArray( var2 );
    glDisableVertexAttribArray( var3 );
    glDisableVertexAttribArray( var4 );
    glDisableVertexAttribArray( var5 );
}
