#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1)in vec2 texCoord;
uniform mat4 u_View;
uniform mat4 u_Model;
out vec2 v_texCoord;
out vec4 v_VertexColor;
void main()
{
    gl_Position = u_View*u_Model*vec4(position,1.0);
    v_texCoord=texCoord;
}
