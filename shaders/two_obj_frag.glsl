#version 460 core

precision mediump float;

out vec4 FragColor;

uniform float time;
uniform int objectType;

void main() {
    FragColor = vec4(1.0, 0.0, 0.0, 1.0);  // Red color
}
