#version 460 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec2 tex;

out vec2 dim;

void main() {
    dim = vec2(1920.0, 1080.0);

    vec4 position = vec4(pos, 1.0);
    // normalize to the fourth quadrant
    position.xy = -position.xy * 2.0 + 1.0;

    gl_Position = position;
}
