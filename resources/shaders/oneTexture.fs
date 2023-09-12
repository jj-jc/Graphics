#version 440 core

in vec4 ourColor;
in vec2 ourTextCoord;

uniform sampler2D ourTexture;

out vec4 FragColor;

void main()
{
    FragColor =/*  vec4(1, 0, 0, 0) * */ texture(ourTexture, ourTextCoord);
}