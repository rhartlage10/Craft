#version 120

attribute vec4 position;
attribute vec3 normal;
attribute vec2 uv;

varying vec2 frag_uv;
uniform mat4 matrix;

uniform vec4 timerPos;
uniform int timer;

void main() {
    gl_Position = matrix * position;
    frag_uv = uv; 
}
