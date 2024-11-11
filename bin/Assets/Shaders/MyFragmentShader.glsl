#version 330 core
out vec4 FragColor;
  
in vec2 texCoords;

uniform sampler2D Sampler;

void main()
{
    FragColor = texture(Sampler,texCoords).rgba;
}