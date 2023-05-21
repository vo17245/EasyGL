#version 330 core

uniform sampler2D u_texture;
out vec4 color;
in vec2 v_texCoord;

void main()
{
    color = texture(u_texture, v_texCoord);
}
