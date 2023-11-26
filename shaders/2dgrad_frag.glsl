#version 460 core
precision mediump float;

in vec2 dim;

out vec4 FragColor;

void main() {
    // 2D gradient
    FragColor = vec4(gl_FragCoord.xy / dim, 1.0, 1.0);
}
