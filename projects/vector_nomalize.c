#include <math.h>
#include <stdio.h>

struct vector3 {
	float x, y, z;
};

void vector3_nomalize(struct vector3 *v)
{
	float norm = sqrt((v->x*v->x)+(v->y*v->y)+(v->z*v->z));
	printf("NORM = %f\n", norm);
	v->x /= norm;
	v->y /= norm;
	v->z /= norm;
}

int main()
{
	struct vector3 v = {3.0, 2.0, -1.0};

	printf("%.3f %.3f %.3f\n", v.x, v.y, v.z);

	vector3_nomalize(&v);
	printf("Normalized:\n");
	printf("%.3f %.3f %.3f\n", v.x, v.y, v.z);
	printf("len = %.3f\n", sqrt((v.x*v.x)+(v.y*v.y)+(v.z*v.z)));

}


