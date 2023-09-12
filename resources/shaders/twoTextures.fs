#version 440 core

in vec4 ourColor;
in vec2 ourTextCoord;

uniform sampler2D ourTexture;
uniform sampler2D ourTexture2;

out vec4 FragColor;

void main()
{
    FragColor =/*  vec4(1, 0, 0, 0) * */ mix(texture(ourTexture, ourTextCoord), texture(ourTexture2, ourTextCoord), 0.5);
    // FragColor =/*  vec4(1, 0, 0, 0) * */ texture(ourTexture, ourTextCoord) * texture(ourTexture2, ourTextCoord);
}