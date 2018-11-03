#include <math.h>

#include "vector.h"

vec2 vec2_New(float x, float y)
{
	vec2 w = { x, y };
	return w;
}

vec2 vec2_Add(vec2 v1, vec2 v2)
{
	return vec2_New(v1.x+v2.x, v1.y+v2.y);
}

vec2 vec2_Sub(vec2 v1, vec2 v2)
{
	return vec2_New(v1.x-v2.x, v1.y-v2.y);
}

vec2 vec2_Mult(vec2 v1, float s)
{
	return vec2_New(v1.x * s, v1.y * s);
}

vec2 vec2_Div(vec2 v1, float s)
{
	return vec2_New(v1.x / s, v1.y / s);
}

float vec2_Mag(vec2 v1)
{
	return sqrt(pow(v1.x, 2) + pow(v1.y, 2));
}

vec2 vec2_Normalize(vec2 v1)
{
	float m = vec2_Mag(v1);
	vec2  v = vec2_New(v1.x, v1.y);

	if (m != 0) {
		return vec2_Div(v, m);
	}

	return v;
}
