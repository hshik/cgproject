#version 330 core


uniform vec4 color; //unifor 변수
out vec4 FragColor;

void main()
{
  FragColor = color;
}