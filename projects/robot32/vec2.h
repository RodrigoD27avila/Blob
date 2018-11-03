#ifndef VEC2_H_INCLUDED
#define VEC2_H_INCLUDED

typedef struct {
	float x;
	float y;
} vec2;

vec2 vec2_New(float x, float y);

vec2 vec2_Add(vec2 v1, vec2 v2);

vec2 vec2_Sub(vec2 v1, vec2 v2);

vec2 vec2_Mult(vec2 v1, float s);

vec2 vec2_Div(vec2 v1, float s);

float vec2_Mag(vec2 v1);

vec2 vec2_Normalize(vec2 v1);

#endif /* VEC2_H_INCLUDED */
