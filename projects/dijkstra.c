#include <string.h >

/* quantidade maxima de vertices */
#define MAXV 100

int madj[MAXV][MAXV];

int dis[MAXV];

void disjkstra(int vi, int v)
{
	/* vertices já visitados, inicialmente nenhum foi */
	char vis[MAXV];
	memset(vis, 0, MAXV);

	/* inicialmete dizemos que a menor distancia entre Vi
	   e outos vértices é infinita.
	*/
	memset(dis, 0x7f, MAXV);
	dis[vi] = 0;

	

	
}
