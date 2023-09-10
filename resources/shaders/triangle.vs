#version 440 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec3 ourColor;

void main()
{
    gl_Position = vec4(aPos, 1.0);  // always have to be this name for position. A verctor of 4 values.
    ourColor = aColor;              // send vertex data to FragmentShader.
}