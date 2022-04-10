#version 120

attribute vec4 position;
attribute vec3 normal;
attribute vec2 uv;

varying vec2 frag_uv;
uniform mat4 matrix;

void main() {
    gl_Position = matrix * position;
    frag_uv = uv;
}
