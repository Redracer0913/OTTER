#version 420

layout(location = 0) in vec2 inUV;

out vec4 frag_color;

layout  (binding = 0) uniform sampler2D u_FinishedFrame;
layout (binding = 30) uniform sampler3D	u_TexColorGrade;				
//affects how greyscale 
//lower the number, closer we are to regualar
uniform float u_Intensity = 1.0;

void main() 
{
	vec4 textureColor = texture(u_FinishedFrame, inUV);

	vec3 scale = vec3((64.0 - 1.0) / 64.0);
	vec3 offset = vec3((1.0 / (2.0 * 64.0));

//	float luminence = 0.2989 * source.r + 0.587 * source.g + 0.114 * source.b;
	frag_color.rgb = texture(u_texColorGrade, scale * textureColor.rgb + offset).rgb;
    frag_color.a = textureColor.a;
}