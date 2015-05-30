#version 120


uniform mat4 MVP;

attribute vec3 position;
attribute vec3 color;


void main()
{
  gl_Position = MVP * vec4( position, 1.0f );
  gl_Position.x = gl_Position.x - 4.0f;
  gl_Position.y = gl_Position.y - 4.0f;
  gl_FrontColor = vec4( color, 1.0f );
  gl_FrontColor.b = dot(gl_Color, gl_Vertex);
  gl_FrontColor.g = dot(gl_Color, gl_Vertex * 2.0);
}
