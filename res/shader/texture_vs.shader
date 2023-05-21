#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1)in vec2 texCoord;
uniform mat4 u_View;
out vec2 v_texCoord;
out vec4 v_VertexColor;
void main()
{
    gl_Position = u_View*vec4(position,1.0);
    v_texCoord=texCoord;
}
