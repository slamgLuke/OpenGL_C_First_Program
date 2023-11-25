#version 460 core

precision mediump float;

out vec4 FragColor;

uniform float time;

void main() {
    float scaledTime = time * 10.;

    float x_pos = gl_FragCoord.x / 600.0;
    float x_color = sin(x_pos * 16. + scaledTime);
    x_color = x_color * 0.5 + 0.5;

    float y_pos = gl_FragCoord.y / 600.0;
    float y_color = sin(y_pos * 16. + scaledTime);
    y_color = y_color * 0.5 + 0.5;

    if (x_color < 0.5) {
        x_color = 0.;
    } else {
        x_color = 1.;
    }

    if (y_color < 0.5) {
        y_color = 0.;
    } else {
        y_color = 1.;
    }

    if (x_color == 1. && y_color == 0.) {
        FragColor = vec4(1., 1., 1., 1.);
    } else if (x_color == 0. && y_color == 1.) {
        FragColor = vec4(1., 1., 1., 1.);
    } else {
        FragColor = vec4(0., 0., 0., 1.);
    }
}
