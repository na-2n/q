#version 420

in vec3 vert_pos;
in vec3 vert_normal;

out vec3 frag_pos;
out vec3 frag_normal;

uniform mat4 proj_mat;
uniform mat4 view_mat;
uniform vec3 chunk_pos;

void main()
{
    frag_pos = vert_pos + chunk_pos;
    frag_normal = vert_normal + chunk_pos;

    gl_Position = proj_mat * view_mat * vec4(frag_pos, 1);
}

