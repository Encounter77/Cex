#include <stdio.h>

#define MAXN 10

double f( int n, double a[], double x );

int main()
{
    int n, i;
    double a[MAXN], x;
				
    scanf("%d %lf", &n, &x);
    for ( i=0; i<=n; i++ )
        scanf(¡°%lf¡±, &a[i]);
    printf("%.1f\n", f(n, a, x));
    return 0;
}

