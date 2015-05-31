#version 120


uniform mat4 MVP;

attribute vec3 position;
attribute vec3 color;
attribute float life;

float currentLife;

float rand(vec2 co){
    return fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453);
}

void main()
{
  //gl_Position = MVP * vec4( position, 1.0f );
  currentLife = mod(life, 40);
  if(currentLife < 10.0f)
  {
    gl_Position = MVP * vec4(position*currentLife, 1.0f);
    //gl_FrontColor = vec4( 0.0f,255.0f,0.0f, 1.0f );
  }
  else if(currentLife > 30.0f)
  {
    gl_Position = MVP * vec4(position*(mod(currentLife,30.0f)-10.0f), 1.0f);
    //gl_FrontColor = vec4( 255.0f,0.0f,0.0f, 1.0f );
  }
  else
  {
    gl_Position = MVP * vec4(position*(10.0f-(currentLife-10.0f)), 1.0f);
    //gl_FrontColor = vec4( 255.0f,255.0f,255.0f, 1.0f );
  }

  float modulR = mod(rand(vec2(life, currentLife)), 255);
  float modulV = mod(rand(vec2(life + 5, currentLife + 2)), 255);
  float modulB = mod(rand(vec2(life + 15, currentLife + 3)), 255);

  gl_FrontColor = vec4( modulR, modulV, modulB, 1.0f );
}

