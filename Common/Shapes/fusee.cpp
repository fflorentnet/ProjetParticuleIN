#include "fusee.h"
#include <math.h>
#include <cstdlib>
#include <iostream>

#define PI 3.14159265

using namespace std;
Fusee::Fusee()
{
    init();
    deathTime = 3.0f;
}


void
Fusee::update()
{
    life+= 0.01f;


    if(life >= explodeTime && !isExploded)
    {
        isExploded = true;
        explosion->setPosition(
                    position[0] + (speed[0] * life),
                    position[1] + (speed[1] * life) + weight[0] * -9.8f * life * life,
                    0.0f);
    }


    if(isExploded)
    {
        explosion->update();
    }
}



void Fusee::init(){

    explosion = new Explosion();
    isExploded = false;

    explodeTime = RandomFloat(0.5f,1.5f);


    float velocity = 4.0f;
    float theta = (PI * 2)/360;
    life = 0.0f;
    float randVelocity = 0.0f;
    float particleAngle = 0.0f;

    randVelocity = RandomFloat(3.5f,velocity*velocity);
    particleAngle = RandomFloat(45,130)*theta;
    speed[0] = cos(particleAngle)*randVelocity;
    speed[1] = sin(particleAngle)*randVelocity;
    speed[2] =  cos(RandomFloat(-PI,PI)) * sin(RandomFloat(-PI,PI))*randVelocity;

    weight[0] = RandomFloat(0.001f,1.0f);

    colorParticles[0] = RandomFloat(50,200);
    colorParticles[1] = RandomFloat(50,200);
    colorParticles[2] = RandomFloat(50,200);

}
void
Fusee::draw()
{
    if (m_Framework->useShader( "simpleMovement" ))
    {
        m_Framework->computeAncillaryMatrices();
        GLint var_id = glGetUniformLocation( m_Framework->getCurrentShaderId(), "MVP" );
        m_Framework->transmitMVP( var_id );

        drawShape();
    }
}


void
Fusee::drawShape()
{
    glEnable( GL_POINT_SMOOTH );
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    if(isExploded)
    {
        explosion->draw();
    }
    else
    {
        GLint var1 = glGetUniformLocation( m_Framework->getCurrentShaderId(), "life" );
        glUniform1f(var1, life);

        GLint var2 = glGetUniformLocation( m_Framework->getCurrentShaderId(), "position" );
        glUniform3f(var2, position[0], position[1], position[2]);
        GLint var3 = glGetUniformLocation( m_Framework->getCurrentShaderId(), "colorParticles" );
        glUniform3f(var3, colorParticles[0]/255, colorParticles[1]/255, colorParticles[2]/255);
        GLint var4 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "velocity" );
        glEnableVertexAttribArray( var4 );
        glVertexAttribPointer( var4, 3, GL_FLOAT, GL_FALSE, 0, speed );

        GLint var5 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "poids" );
        glEnableVertexAttribArray( var5 );
        glVertexAttribPointer( var5, 1, GL_FLOAT, GL_FALSE, 0, weight);

        glPointSize(10);

        glDrawArrays( GL_POINTS, 0, 1 );

        glDisableVertexAttribArray( var1 );
        glDisableVertexAttribArray( var2 );
        glDisableVertexAttribArray( var3 );
        glDisableVertexAttribArray( var4 );
        glDisableVertexAttribArray( var5 );

    }



}
