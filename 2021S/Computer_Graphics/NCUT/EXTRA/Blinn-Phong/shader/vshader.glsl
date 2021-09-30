#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

out vec3 fragPos;
out vec3 fragNormal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    fragPos = aPos;
    fragNormal = aNormal;
    gl_Position = projection * view * model * vec4(aPos, 1.0f);
}