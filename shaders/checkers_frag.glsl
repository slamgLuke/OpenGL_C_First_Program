#version 460 core

in vec2 dim;

precision mediump float;
uniform float time;
uniform int objectType;

out vec4 FragColor;

void main() {
    float scaledTime = time * 5.;

    float x_pos = gl_FragCoord.x / dim.x;
    float x_color = sin(x_pos * 64. + scaledTime);
    x_color = x_color * 0.5 + 0.5;

    float y_pos = gl_FragCoord.y / dim.y;
    float y_color = sin(y_pos * 64. + scaledTime);
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

    if (objectType == 0) {
        if (x_color == 1. && y_color == 0.) {
            FragColor = vec4(1., 0., 1., 1.);
        } else if (x_color == 0. && y_color == 1.) {
            FragColor = vec4(0., 1., 1., 1.);
        } else {
            FragColor = vec4(0., 0., 0., 1.);
        }
    } else {
        FragColor = vec4(1., 1., 0., 1.);
    }
}
