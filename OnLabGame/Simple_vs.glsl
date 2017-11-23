#version 330 core
layout (location = 0) in vec3 aPos;

uniform mat4 S;
uniform mat4 R;
uniform mat4 T;
uniform mat4 V;
uniform mat4 P;

void main()
{
	mat4 M = S*R*T;
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0) * M * V * P;
}