#version 330 core
precision highp float;

out vec4 FragmentColor;

uniform vec3 color;
uniform vec3 sun;
uniform vec3 cam;

in vec3 position;
in vec3 normal;

void main(){
	vec3 dir = normalize(sun - position);
	float cos = dot(-dir,normal);			// vec3(0.0f, 0.0f, -1.0f));
	FragmentColor = vec4(color * cos, 1);							//vec4(normal.xy, -normal.z, 1.0f);
}
