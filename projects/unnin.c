#include <stdio.h>

typedef struct
{
    int x, y;
    int w, h;

}rectangle;

typedef struct
{
    int x, y;
    int r;

} circle;

typedef union
{
    rectangle rect;
    circle    circ;

} types;


typedef struct
{
    int count;
    types items[255];

}vector;

circle create_circle(int x, int y, int r)
{
    circle c = {x, y, r};
    return c;
}

void vector_add_circle(vector *v, circle c)
{
    v->items[v->count].circ = c;
    v->count += 1;
}

rectangle create_rectangle(int x, int y, int w, int h)
{
    rectangle rect = {x, y, w, h};
    return rect;
}

void vector_add_rectangle(vector *v, rectangle r)
{
    v->items[v->count].rect = r;
    v->count += 1;
}

int main()
{

    vector v = {0};

    vector_add_rectangle(&v, create_rectangle(0, 0, 10, 10));
    vector_add_rectangle(&v, create_rectangle(0, 0, 11, 11));
    vector_add_rectangle(&v, create_rectangle(0, 0, 12, 12));
    vector_add_rectangle(&v, create_rectangle(0, 0, 13, 13));

    printf("%i\n", v.count);
    printf("x = %i\n", v.items[0].rect.x);
    printf("y = %i\n", v.items[0].rect.y);
    printf("w = %i\n", v.items[0].rect.w);
    printf("h = %i\n", v.items[0].rect.h);

    return 0;
}

