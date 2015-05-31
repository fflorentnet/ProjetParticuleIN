#version 120


uniform mat4 MVP;

uniform float life;
uniform vec3 position;
uniform vec3 colorParticles;

attribute vec3 velocity;

float rand(vec2 co){
    return fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453);
}

void main()
{
  gl_Position = MVP * vec4( position, 1.0f );
  gl_Position += vec4( velocity, 1.0f )*life;//*vec4(1.0f,0.06f,1.0f,1.0f);

  //gl_FrontColor.r = colorParticles.x;
  //gl_FrontColor.g = colorParticles.y;
  //gl_FrontColor.b = colorParticles.z;
  //gl_FrontColor = vec4( colorParticles, 1.0f ); // BUG : impossible de récupérer la couleur ?!

    float modulR = mod(rand(vec2(life, life)), 255);
    float modulV = mod(rand(vec2(life + 5, life + 2)), 255);
    float modulB = mod(rand(vec2(life + 15, life + 3)), 255);

    gl_FrontColor = vec4( modulR, modulV, modulB, 1.0f );
}
