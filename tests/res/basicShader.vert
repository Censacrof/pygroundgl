#version 120

attribute vec3 _position;
attribute vec2 _texCoord;

uniform mat4 _transform;

varying vec2 texCoord;

void main()
{
    gl_Position = _transform * vec4(_position, 1.0); //vec4(position, 1.0);
    texCoord = _texCoord;
}