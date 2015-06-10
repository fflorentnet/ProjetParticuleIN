#version 120


varying float transparence;
void main()
{
  gl_FragColor = vec4( gl_Color.rgb, transparence );
}
