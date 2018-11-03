#include <cstdio>

#define INF_MAX 2147483647

int main ()
{
    int n;
    int arr [25];
 
    while ( scanf ("%d", &n) != EOF ) {
        for ( int i = 0; i < n; i++ ) scanf ("%d", &arr [i]);
 
        int lim = 1 << n;
        int mini = INF_MAX;
 
        while ( lim ) {
            int sum = 0;
            for ( int i = 0; i < n; i++ ) {
                if ( lim & (1 << i) ) sum += arr [i];
                else sum -= arr [i];
            }
            if ( sum >= 0 && mini > sum ) mini = sum;
            lim--;
        }
 
        printf ("%d\n", mini);
    }
 
    return 0;
}
