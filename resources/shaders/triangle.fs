#version 440 core
out vec4 FragColor; // always declere an ouput variable of 4 values.

in vec3 ourColor; // input variable from vs (same name and type that the output variable in vs)

void main()
{
    FragColor = vec4(ourColor, 1.0f);
}