#version 120


uniform mat4 MVP;


uniform vec3 position;
uniform vec3 colorParticles;

attribute vec3 velocity;
attribute float poids;
attribute float lives;

float currentLife;

void main()
{
        vec4 currentPos;
        currentPos = vec4( position + (velocity * lives) + poids * (vec3(0, -9.8f, 0) * lives * lives), 1.0f);

       gl_Position = currentPos * MVP;
       gl_FrontColor = vec4( colorParticles, 1.0f );
}

