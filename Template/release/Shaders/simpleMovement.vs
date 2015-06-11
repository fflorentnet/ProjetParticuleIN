#version 120


uniform mat4 MVP;

uniform float life;
uniform vec3 position;
uniform vec3 colorParticles;

attribute vec3 velocity;
attribute float poids;

varying out vec4 currentPosition;

float rand(vec2 co){
    return fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453);
}

void main()
{
       vec4 currentPos = vec4( position + (velocity * life) + poids * (vec3(0, -9.8f, 0) * life * life), 1.0f);
       gl_Position = currentPos * MVP;

       currentPosition = currentPos; // Ici j'aimerai retourner la position actuelle !

    //gl_FrontColor = vec4( 255, 255, 255, 1.0f );
}

