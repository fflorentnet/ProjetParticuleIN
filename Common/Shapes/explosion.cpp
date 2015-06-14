#include "explosion.h"
#include <math.h>
#include <cstdlib>
#include <iostream>

using namespace std;

#define PI 3.14159265


Explosion::Explosion()
{
    init();
    deathTime = 1.0f;
}

void
Explosion::update()
{
    life+= 0.01f; // contient la vie de l'ensemble / du phenomene
}
void Explosion::init(){
    float velocity = 4.0f;
    float theta = (PI * 2)/NB_PARTICULES;
    life = 0.0f;
    float randVelocity = 0.0f;
    float particleAngle = 0.0f;

    for( GLuint i = 0; i < NB_PARTICULES * 3; i+=3 )
    {
        randVelocity = RandomFloat(0.2f,velocity*velocity);
        particleAngle = i*theta;
        m_tabSpeed[i+0] = cos(particleAngle)*randVelocity;
        m_tabSpeed[i+1] = sin(particleAngle)*randVelocity;
        m_tabSpeed[i+2] = sin(RandomFloat(-PI, PI))*randVelocity;
    }
    for (GLuint i = 0; i <NB_PARTICULES ; i++)
        m_Weight[i] = RandomFloat(0.001f,1.0f);

    colorParticles[0] = RandomFloat(50,200);
    colorParticles[1] = RandomFloat(50,200);
    colorParticles[2] = RandomFloat(50,200);

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

void
Explosion::drawShape()
{

    glEnable( GL_POINT_SMOOTH );
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    if (life/0.01f > 15)
    {
        float tLife = 0;
        for (int i = 15 ; i >= 0; i--)
        {
            tLife = life - i * 0.01;

            GLint var1 = glGetUniformLocation( m_Framework->getCurrentShaderId(), "life" );
            glUniform1f(var1, tLife);

            GLint var6 = glGetUniformLocation( m_Framework->getCurrentShaderId(), "rlife" );
            glUniform1f(var6, i);

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
            if (i == 0)
                glPointSize(3);
            glDrawArrays( GL_POINTS, 0, NB_PARTICULES );

            glDisableVertexAttribArray( var1 );
            glDisableVertexAttribArray( var2 );
            glDisableVertexAttribArray( var3 );
            glDisableVertexAttribArray( var4 );
            glDisableVertexAttribArray( var5 );
            glDisableVertexAttribArray( var6 );
        }
    }
}
