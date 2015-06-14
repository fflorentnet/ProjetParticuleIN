#version 120


uniform mat4 MVP;

uniform float life;
uniform vec3 position;
uniform vec3 colorParticles;

attribute vec3 velocity;
attribute float poids;

void main()
{
       vec4 currentPos = vec4( position + (velocity * life) + poids * (vec3(0, -9.8f, 0) * life * life), 1.0f);
       gl_Position = MVP * currentPos;
       gl_FrontColor = vec4( colorParticles, 1.0f );
}

