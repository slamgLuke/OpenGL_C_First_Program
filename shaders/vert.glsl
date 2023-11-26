#version 460 core

layout(location = 0) in vec3 bgPos;
layout(location = 1) in vec3 cubePos;

uniform int objectType;

out vec2 dim;

void main() {
    dim = vec2(1920.0, 1080.0);

    vec4 position;
    if (objectType == 0) {
        position = vec4(bgPos, 1.0);
    } else {
        position = vec4(cubePos, 1.0);
    }

    position.xy = -position.xy * 2.0 + 1.0;


    gl_Position = position;
}
