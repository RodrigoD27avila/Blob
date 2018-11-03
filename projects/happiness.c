#include <stdio.h>
#include <stdlib.h>
#include <math.h>

///////////////////////////////////
typedef struct __NODE {
	struct __NODE *next;
	int num;
	int hpns;
} NODE;

typedef struct __TOWN {
	struct __NODE *first;
	int num;
	int hpns;
} TOWN;

static TOWN *TOWN_New(int num, int hpns)
{
	TOWN *t = malloc(sizeof(TOWN));
    t->first = NULL;
	t->num   = num;
	t->hpns  = hpns;
	return t;
}

static NODE *NODE_New(int num, int hpns)
{
	NODE *n = malloc(sizeof(NODE));
	n->next = NULL;
	n->num  = num;
	n->hpns = hpns;
	return n;
}

///////////////////////////////////

static int N, K;
// towns
static TOWN **T;
// best towns
static int *B;
// visited towns
static int *V;
// ancestor
static int *A;
// solve
static int *S;

int compar(const void *a, const void *b)
{
    const int *aa = (const int *)a;
    const int *bb = (const int *)b;

	const TOWN *ta = T[*aa];
	const TOWN *tb = T[*bb];
	return (ta->hpns<tb->hpns) ? 1 : (ta->hpns>tb->hpns) ? -1 : 0;
}

void insert(int a, int b, int c)
{
    TOWN *t    = T[a];
    NODE *node = t->first;
    NODE *prev = NULL;
    NODE *nodenew = NODE_New(b, c);

    int i=1;
    while (node != NULL && B[i] != b) {
        if (node->num == B[i]) {
            prev = node;
            node = node->next;
        }

        i++;
    }

    if (prev) {
        prev->next  = nodenew;
        nodenew->next = node;
    } else {
        nodenew->next = t->first;
        t->first    = nodenew;
    }
}

static void dfs(TOWN *root, int count)
{
    NODE *n = root->first;
    while (n != NULL && V[n->num] > 0) {
        n = n->next;
    }

    if (n != NULL) {
        int index = n->num;
        V[index] = count+n->hpns+T[index]->hpns;
        A[index] = root->num;
        dfs(T[index], V[index]);
    }
}

static int solve()
{
    int i;
    for (i=1; i<=N; i++) {
        if (!V[B[i]]) {
            V[B[i]] = T[B[i]]->hpns;
            A[B[i]] = 0;
            dfs(T[B[i]], V[B[i]]);
        }
    }

    int hpns = 0, index = 0;
    for (i=1; i<=N; i++) {
        if (V[i] > hpns) {
            hpns  = V[i];
            index = i;
        }
    }

    i=1;
    while (index > 0) {
        S[i]  = index;
        index = A[index];
        i += 1;
    }

    return i;
}

void init()
{
    T = calloc(50001, sizeof(TOWN *));
    B = calloc(50001, sizeof(int));
    V = calloc(50001, sizeof(int));
    A = calloc(50001, sizeof(int));
    S = calloc(50001, sizeof(int));
}

void quit()
{
    int i;
    for (i=1; i<=N; i++) {
        TOWN *t = T[i];
        NODE *n = t->first;
        while (n != NULL) {
            NODE *tmp = n;
            n = n->next;
            free(tmp);
        }
        free(t);
    }
    free(T);
    free(B);
    free(V);
    free(A);
    free(S);
}

int main()
{
    init();

	scanf("%d %d", &N, &K);
	int i;
	for (i=0; i<N; i++) {
		int h;
		scanf("%d", &h);
	    T[i+1] = TOWN_New(i+1, h);
	}

	for (i=0;i<=N;i++){
		B[i]=i;
	}

	qsort(&B[1], N, sizeof(int), compar);

	for (i=0; i<K; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		insert(a, b, c);
		insert(b, a, c);
	}

    int n = solve()-1;

    /*
    printf("solve = %i\n", n);


    for (i=1; i<=N; i++) {
        printf("%3i ", V[i]);
    }
    printf("\n");

    for (i=1; i<=N; i++) {
        printf("%3i ", A[i]);
    }
    printf("\n");

    for (i=1; i<=N; i++) {
        printf("%i ", B[i]);
    }
    printf("\n");


    NODE *n = T[1]->first;
    while (n != NULL) {
        printf(" > %i\n", n->num);
        n = n->next;
    }
*/
    printf("%i\n", V[S[1]]);
	printf("%i\n", n);
	for (i=n; i>1; i--) {
		printf("%i ", S[i]);
	}
	printf("%i\n", S[1]);

    quit();

	return 0;
}
