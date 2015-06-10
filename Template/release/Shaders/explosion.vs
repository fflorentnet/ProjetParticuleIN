#version 120

uniform mat4 MVP;

uniform vec2 random;
uniform float life;
uniform vec3 position;
uniform vec3 colorParticles;

attribute vec3 velocity;
attribute float poids;



varying float transparence;

void main()
{
  transparence = 1.2f-life;
  gl_Position = vec4( position + (velocity * life/2) + poids * (vec3(0, -9.8f, 0) * life * life), 1.0f) * MVP;
 gl_FrontColor.rgba = vec4( colorParticles, transparence); 
}
