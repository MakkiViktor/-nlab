#version 330 core
precision highp float;

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 norm;

uniform mat4 MVP;
uniform mat4 M;
uniform mat4 Minv;


out vec3 position;
out vec3 normal;

void main()
{
    gl_Position = MVP * vec4(aPos, 1.0f);
	position = (M * vec4(aPos, 1.0f)).xyz;
	normal = (Minv * vec4(norm, 0)).xyz;
}