#include "particules.h"

GLfloat positionsParticules[] =
{
    0.0f, 0.0f, 0.0f,
    1.0f, 0.0f, 0.0f,
    2.0f, 0.0f, 0.0f,
    3.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 2.0f, 0.0f,
    0.0f, 3.0f, 0.0f,
    0.0f, 0.0f, 1.0f,
    0.0f, 0.0f, 2.0f,
    0.0f, 0.0f, 3.0f
};

GLfloat g_TabColors3[] =
{
    1.0f, 0.0f, 0.0f,
    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    1.0f, 0.0f, 0.0f,
    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f,
    0.0f, 0.0f, 1.0f,
    0.0f, 0.0f, 1.0f
};

GLfloat g_TabLifes[] =
{
    1.0f,
    1.0f,
    0.0f,
    1.0f,
    1.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f
};



Particules::Particules()
{
    life = 0.0f;
}
void
Particules::update()
{
    life+= 0.1f; // contient la vie de l'ensemble / du phenomene
    for( GLuint i = 0; i < 10; ++i )
    {
        g_TabLifes[i] = life; // Chaque particule a sa variable de vie associée
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

void
Particules::drawShape()
{
    GLint var1 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "position" );
    glEnableVertexAttribArray( var1 );
    glVertexAttribPointer( var1, 3, GL_FLOAT, GL_FALSE, 0, positionsParticules );
    GLint var2 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "color" );
    glEnableVertexAttribArray( var2 );
    glVertexAttribPointer( var2, 3, GL_FLOAT, GL_FALSE, 0, g_TabColors3 );

    // On passe le tableau contenant 1 variable de vie / sommet
    GLint var3 = glGetAttribLocation( m_Framework->getCurrentShaderId(), "life" );
    glEnableVertexAttribArray( var3 );
    glVertexAttribPointer( var3, 1, GL_FLOAT, GL_FALSE, 0, g_TabLifes );

    glPointSize(10);
    //glDrawElements( GL_POINTS, 10, GL_UNSIGNED_INT, positionsParticules);
    glDrawArrays( GL_POINTS, 0, 10 );

    glDisableVertexAttribArray( var1 );
    glDisableVertexAttribArray( var2 );
    glDisableVertexAttribArray( var3 );
}

