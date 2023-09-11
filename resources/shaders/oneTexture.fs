#version 440 core

in vec4 ourColor;
in vec2 ourTextCoord;

uniform sampler2D ourTexture;

out vec4 FragColor;

void main()
{
    FragColor = ourColor * texture(ourTexture, ourTextCoord);
}