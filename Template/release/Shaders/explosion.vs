#version 120

uniform mat4 MVP;

uniform vec2 random;
uniform float life;
uniform vec3 position;
uniform vec3 colorParticles;
uniform float rlife;

attribute vec3 velocity;
attribute float poids;



varying float transparence;

void main()
{
        transparence = 1.2f - life - rlife * 0.05f;
        gl_Position = MVP * vec4( position + (velocity * life) + poids * (vec3(0, -9.8f, 0) * life * life), 1.0f);
	gl_FrontColor.rgba = vec4( colorParticles, transparence); 
 }
