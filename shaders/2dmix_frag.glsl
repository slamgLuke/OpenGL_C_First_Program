#version 460 core
precision mediump float;

out vec4 FragColor;

void main() {
    // 2D mix gradient
    vec4 top_left = vec4(0.5, 0.1, 0.9, 1.0);
    vec4 top_right = vec4(0.3, 1.0, 0.8, 1.0);

    vec4 bottom_left = vec4(0.8, 0.6, 0.1, 1.0);
    vec4 bottom_right = vec4(0.7, 0.1, 0.2, 1.0);

    vec4 top = mix(top_left, top_right, gl_FragCoord.x / 600.0);
    vec4 bottom = mix(bottom_left, bottom_right, gl_FragCoord.x / 600.0);

    vec4 color = mix(bottom, top, gl_FragCoord.y / 400.0);

    FragColor = color;
}
