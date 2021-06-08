#version 330 core
in vec3 fragPos;
in vec3 fragNormal;

out vec4 FragColor;

uniform vec3 lightPos;
uniform vec3 viewPos;

void main()
{
    vec3 color = vec3(1.0f, 0.5f, 0.2f);
    // ambient
    float Ka = 0.3f;
    vec3 ambient = Ka * color;
    // diffuse
    float Kd = 0.8f;
    vec3 lightDir = normalize(lightPos - fragPos);
    vec3 normal = normalize(fragNormal);
    vec3 diffuse = Kd * color * max(dot(lightDir, normal), 0.0f);
    // specular
    float Ks = 0.5f;
    float shininess = 32.0f;
    vec3 specColor = vec3(1.0f, 1.0f, 1.0f);
    vec3 viewDir = normalize(viewPos - fragPos);
    // Blinn-Phong
    vec3 specular = Ks * specColor * pow(max(dot(normal, normalize(lightDir + viewDir)), 0.0), shininess);
    // Phong
    //vec3 specular = Ks * specColor * pow(max(dot(viewDir, reflect(-lightDir, normal)), 0.0), shininess);

    FragColor = vec4(ambient + diffuse + specular, 1.0f);
}