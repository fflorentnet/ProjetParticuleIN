#include "fusee.h"
#include <math.h>
#include <cstdlib>
#include <iostream>

#define PI 3.14159265

using namespace std;
Fusee::Fusee()
{
    init();
}
void Fusee::setPosition(float x, float y, float z)
{
    position[0] = x;
    position[1] = y;
    position[2] = z;
}


void
Fusee::update()
{
    life+= 0.01f;


    if(life >= explodeTime && !isExploded)
    {
        isExploded = true;
        explosion->setPosition(position[0],position[1],position[2]); // BADABOUM, on explose tout ! Il faut currentPosition ici !
    }


    if(isExploded)
    {
        explosion->update();
    }
}



void Fusee::init(){

    explosion = new Explosion();
    isExploded = false;

    explodeTime = 10.0f;


    float velocity = 4.0f;
    float theta = (PI * 2)/360;
    life = 0.0f;
    float randVelocity = 0.0f;
    float particleAngle = 0.0f;

    randVelocity = RandomFloat(0.5f,velocity*velocity);
    particleAngle = RandomFloat(45,130)*theta;
    speed[0] = cos(particleAngle)*randVelocity;
    speed[1] = sin(particleAngle)*randVelocity;
    speed[2] = 0;

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

float
Fusee::RandomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

void
Fusee::drawShape()
{
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


        // JE TROUVE PAS COMMENT FAIRE POUR RECUPERER CURRENT POSITION ICI :


        /*GLint var_id = glGetUniformfv( m_Framework->getCurrentShaderId(), "currentPosition" );

        shader.setProgramOutput(0,"outputF");
            shader.setVertexAttribName(VSShaderLib::VERTEX_COORD_ATTRIB, "position");
        cout << returnedPosition[0] << " " << returnedPosition[1];*/

        glPointSize(10);

        glDrawArrays( GL_POINTS, 0, 1 );

        glDisableVertexAttribArray( var1 );
        glDisableVertexAttribArray( var2 );
        glDisableVertexAttribArray( var3 );
        glDisableVertexAttribArray( var4 );
        glDisableVertexAttribArray( var5 );

    }



}
