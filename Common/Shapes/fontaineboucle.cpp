#include "fontaineboucle.h"
#include <math.h>
#include <cstdlib>
#include <iostream>

#define PI 3.14159265

using namespace std;
FontaineBoucle::FontaineBoucle()
{
    init();
    deathTime = 5.0f;
}

void
FontaineBoucle::update()
{
    life+= 0.01f;

    for (GLuint i = 0; i <NB_PARTICULES_FONTAINE_BOUCLE ; i++)
    {
        m_lives[i] += 0.01f;

        if(m_lives[i] >= NB_PARTICULES_FONTAINE_BOUCLE*0.001f)
        {
            m_lives[i] = 0.0f;
        }
    }
}



void
FontaineBoucle::init(){
    float velocity = 4.0f;
    float theta = (PI * 2)/360;
    life = 0.0f;
    float randVelocity_x = 0.0f;
    float randVelocity_y = 0.0f;
    float particleAngle = 0.0f;

    for( GLuint i = 0; i < NB_PARTICULES_FONTAINE_BOUCLE * 3; i+=3 )
    {
        randVelocity_x = RandomFloat(1.0f,velocity);
        randVelocity_y = RandomFloat(velocity,velocity*2);
        particleAngle = RandomFloat(65,125)*theta;
        m_tabSpeed[i+0] = cos(particleAngle)*randVelocity_x;
        m_tabSpeed[i+1] = sin(particleAngle)*randVelocity_y;
        m_tabSpeed[i+2] = cos(RandomFloat(-PI,PI))*sin(RandomFloat(-PI,PI)) * RandomFloat(1.0f,velocity);
    }


    for (GLuint i = 0; i <NB_PARTICULES_FONTAINE_BOUCLE ; i+=2)
    {
        m_lives[i] = i*0.001f;
        m_lives[i+1] = i*0.001f;
    }

    for (GLuint i = 0; i <NB_PARTICULES_FONTAINE_BOUCLE ; i++)
        m_Weight[i] = RandomFloat(0.01f,0.5f);

    colorParticles[0] = RandomFloat(50,200);
    colorParticles[1] = RandomFloat(50,200);
    colorParticles[2] = RandomFloat(50,200);

}
void
FontaineBoucle::draw()
{
    if (m_Framework->useShader( "fountain" ))
    {
        m_Framework->computeAncillaryMatrices();
        GLint var_id = glGetUniformLocation( m_Framework->getCurrentShaderId(), "MVP" );
        m_Framework->transmitMVP( var_id );

        drawShape();
    }
}

void
FontaineBoucle::drawShape()
{
   // for (int i = 0; i < life/0.01f;++i)

     //   float tLife = i * 0.001f;
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

        GLint var1 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "lives" );
        glEnableVertexAttribArray( var1 );
        glVertexAttribPointer( var1, 1, GL_FLOAT, GL_FALSE, 0, m_lives);

        /*GLint var6 = glGetUniformLocation( m_Framework->getCurrentShaderId(), "tLife" );
        glUniform1f(var6, tLife);*/


        glPointSize(2);

        glDrawArrays( GL_POINTS, 0, NB_PARTICULES_FONTAINE_BOUCLE );

        glDisableVertexAttribArray( var1 );
        glDisableVertexAttribArray( var2 );
        glDisableVertexAttribArray( var3 );
        glDisableVertexAttribArray( var4 );
        glDisableVertexAttribArray( var5 );

}

