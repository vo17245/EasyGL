#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1)in vec4 color;
uniform mat4 u_View;
void main()
{
    gl_Position = u_View*position;
}
