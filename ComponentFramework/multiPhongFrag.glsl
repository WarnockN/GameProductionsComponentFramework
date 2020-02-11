#version 460
in  vec3 vertNormal;
in  vec3 lightDir;
in  vec3 lightDir2;
in  vec3 eyeDir;
out vec4 fragColor;

void main() { 
	vec4 ks[2] = vec4[] (vec4(0.3, 0.3, 0.3, 0.0), vec4(0.0, 0.4, 0.0, 0.0));
	vec4 kd[2] = vec4[] (vec4(0.6, 0.0, 0.6, 0.0), vec4(0.0, 0.0, 0.6, 0.0)); /// const means it cannot be changed just like C++
	vec4 ka = 0.1 * kd[0] * kd[1];

	float diff = max(dot(vertNormal, lightDir[0]), 0.0);
	float diff2 = max(dot(vertNormal, lightDir[1], 0.0);

	/// Reflection is based incedent which means a vector from the light source
	/// not the direction to the light source

	vec3 reflection = normalize(reflect(-lightDir, vertNormal));
	vec3 reflection2 = normalize(reflect(-lightDir2, vertNormal));

	float spec = max(dot(eyeDir, reflection), 0.0);
	float spec2 = max(dot(eyeDir, reflection2), 0.0);


	fragColor =  ka + ((diff * kd[0]) + (spec * ks[0]) + (diff2 * kd[1]) + (spec2 * ks[1]))/2;

} 

