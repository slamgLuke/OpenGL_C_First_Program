#version 460 core
precision mediump float;

out vec4 FragColor;

void main() {
    // 2D gradient
    FragColor = vec4(gl_FragCoord.xy / vec2(600, 400), 1.0, 1.0);
}
