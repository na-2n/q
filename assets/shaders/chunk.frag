#version 420

in vec3 frag_pos;
in vec3 frag_normal;

out vec4 frag_color;

uniform vec3 light_pos = vec3(32, 32, 32);
uniform vec3 light_color = vec3(1, 1, 1);

void main()
{
    vec3 color = vec3(1, 1, 1);
    vec3 norm = normalize(frag_normal);
    vec3 light_dir = normalize(light_pos - frag_pos);

    float diffuse_factor = max(dot(norm, light_dir), 0);
    vec3 diffuse = diffuse_factor * light_color;

    frag_color = vec4(diffuse * color, 1);
}

