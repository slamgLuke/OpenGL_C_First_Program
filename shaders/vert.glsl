#version 460 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec2 tex;

out vec2 vpos;

void main() {
    vpos = tex;

    vec4 position = vec4(pos, 1.0);
    // normalize to the fourth quadrant
    position.xy = -position.xy * 2.0 + 1.0;

    gl_Position = position;
}
