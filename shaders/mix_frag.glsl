#version 460 core
precision mediump float;

out vec4 FragColor;

void main() {
    // 1D mix gradient
    vec4 color1 = vec4(0.5, 0.1, 0.9, 1.0);
    vec4 color2 = vec4(0.1, 0.8, 0.7, 1.0);
    vec4 color = mix(color1, color2, gl_FragCoord.x / 600.0);

    FragColor = color;
}
