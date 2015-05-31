#include "particules.h"
#include <cstdlib>

Particules::Particules()
{
    life = 0.0f;
    float currentVal = 0.0f;
    int counter = 0;
    for( GLuint i = 0; i < NB_PARTICULES*POINTS; i += POINTS )
    {

        m_tabVertices[i] = RandomFloat(0,currentVal);
        m_tabVertices[i+1] = 0.0f;
        m_tabVertices[i+2] = 0.0f;

        m_tabVertices[i+3] = 0.0f;
        m_tabVertices[i+4] = RandomFloat(0,currentVal);
        m_tabVertices[i+5] = 0.0f;

        m_tabVertices[i+6] = 0.0f;
        m_tabVertices[i+7] = 0.0f;
        m_tabVertices[i+8] = RandomFloat(0,currentVal);

        m_tabVertices[i+9] = RandomFloat(0,currentVal);
        m_tabVertices[i+10] = RandomFloat(0,currentVal);
        m_tabVertices[i+11] = 0.0f;

        m_tabVertices[i+12] = 0.0f;
        m_tabVertices[i+13] = RandomFloat(0,currentVal);
        m_tabVertices[i+14] = RandomFloat(0,currentVal);

        m_tabVertices[i+15] = RandomFloat(0,currentVal);
        m_tabVertices[i+16] = 0.0f;
        m_tabVertices[i+17] = RandomFloat(0,currentVal);

        m_tabVertices[i+18] = RandomFloat(0,currentVal);
        m_tabVertices[i+19] = RandomFloat(0,currentVal);
        m_tabVertices[i+20] = RandomFloat(0,currentVal);


        m_tabColors[i] = 0.0f;
        m_tabColors[i+1] = 0.0f;
        m_tabColors[i+2] = 0.0f;

        m_tabColors[i+3] = 0.0f;
        m_tabColors[i+4] = 0.0f;
        m_tabColors[i+5] = 0.0f;

        m_tabColors[i+6] = 0.0f;
        m_tabColors[i+7] = 0.0f;
        m_tabColors[i+8] = 0.0f;

        m_tabColors[i+9] = 0.0f;
        m_tabColors[i+10] = 0.0f;
        m_tabColors[i+11] = 0.0f;

        m_tabColors[i+12] = 0.0f;
        m_tabColors[i+13] = 0.0f;
        m_tabColors[i+14] = 0.0f;

        m_tabColors[i+15] = 0.0f;
        m_tabColors[i+16] = 0.0f;
        m_tabColors[i+17] = 0.0f;

        m_tabColors[i+18] = 0.0f;
        m_tabColors[i+19] = 0.0f;
        m_tabColors[i+20] = 0.0f;



        m_tabLives[counter*7] = 0.0f;
        m_tabLives[counter*7+1] = 0.0f;
        m_tabLives[counter*7+2] = 0.0f;
        m_tabLives[counter*7+3] = 0.0f;
        m_tabLives[counter*7+4] = 0.0f;
        m_tabLives[counter*7+5] = 0.0f;
        m_tabLives[counter*7+6] = 0.0f;

        counter++;
        currentVal += 0.2f;
    }
}
void
Particules::update()
{
    life+= 0.1f; // contient la vie de l'ensemble / du phenomene
    for( GLuint i = 0; i < NB_PARTICULES * 7; ++i )
    {
        m_tabLives[i] = life; // Chaque particule a sa variable de vie associée
    }
}

void
Particules::draw()
{
    if (m_Framework->useShader( "particules" ))
    {
        m_Framework->computeAncillaryMatrices();
        GLint var_id = glGetUniformLocation( m_Framework->getCurrentShaderId(), "MVP" );
        m_Framework->transmitMVP( var_id );

        drawShape();
    }
}

float
Particules::RandomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

void
Particules::drawShape()
{
    GLint var1 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "position" );
    glEnableVertexAttribArray( var1 );
    glVertexAttribPointer( var1, 3, GL_FLOAT, GL_FALSE, 0, m_tabVertices );
    GLint var2 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "color" );
    glEnableVertexAttribArray( var2 );
    glVertexAttribPointer( var2, 3, GL_FLOAT, GL_FALSE, 0, m_tabColors );

    // On passe le tableau contenant 1 variable de vie / sommet
    GLint var3 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "life" );
    glEnableVertexAttribArray( var3 );
    glVertexAttribPointer( var3, 1, GL_FLOAT, GL_FALSE, 0, m_tabLives );

    glPointSize(10);
    //glDrawElements( GL_POINTS, 10, GL_UNSIGNED_INT, positionsParticules);
    glDrawArrays( GL_POINTS, 0, NB_PARTICULES * 7 );

    glDisableVertexAttribArray( var1 );
    glDisableVertexAttribArray( var2 );
    glDisableVertexAttribArray( var3 );
}

