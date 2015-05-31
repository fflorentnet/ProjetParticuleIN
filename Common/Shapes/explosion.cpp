#include "explosion.h"
#include <math.h>
#include <cstdlib>
#include <iostream>

using namespace std;

#define PI 3.14159265

Explosion::Explosion()
{
    float velocity = 4.0f;
    float angle = (PI * 2)/NB_PARTICULES;

    float randVelocity = 0.0f;
    float particleAngle = 0.0f;

    for( GLuint i = 0; i < NB_PARTICULES * 3; i+=3 )
    {
        randVelocity = RandomFloat(velocity,velocity*2);
        particleAngle = i*angle;
        m_tabSpeed[i] = cos(particleAngle)*randVelocity;
        m_tabSpeed[i+1] = sin(particleAngle)*randVelocity;
        m_tabSpeed[i+2] = 0.0f;
    }
    colorParticles[0] = RandomFloat(0,255);
    colorParticles[1] = RandomFloat(0,255);
    colorParticles[2] = RandomFloat(0,255);

    cout << colorParticles[0] << " " <<  colorParticles[1] << " " <<  colorParticles[2] << endl;

}



void
Explosion::update()
{
    life+= 0.1f; // contient la vie de l'ensemble / du phenomene
    if(life > 15.0f)
    {
        life = 0.0f;
        colorParticles[0] = RandomFloat(0.0f,255.0f);
        colorParticles[1] = RandomFloat(0.0f,255.0f);
        colorParticles[2] = RandomFloat(0.0f,255.0f);
        cout << colorParticles[0] << " " <<  colorParticles[1] << " " <<  colorParticles[2] << endl;
    }
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
    GLint var1 = glGetUniformLocation( m_Framework->getCurrentShaderId(), "life" );
    glUniform1f(var1, life);
    GLint var2 = glGetUniformLocation( m_Framework->getCurrentShaderId(), "position" );
    glUniform3f(var2, position[0], position[1], position[2]);
    GLint var3 = glGetUniformLocation( m_Framework->getCurrentShaderId(), "colorParticles" );
    glUniform3f(var3, colorParticles[0], colorParticles[1], colorParticles[2]);
    GLint var4 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "velocity" );
    glEnableVertexAttribArray( var4 );
    glVertexAttribPointer( var4, 3, GL_FLOAT, GL_FALSE, 0, m_tabSpeed );

    glPointSize(10);
    glDrawArrays( GL_POINTS, 0, NB_PARTICULES );

    glDisableVertexAttribArray( var4 );
}
