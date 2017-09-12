#include <stdio.h>

void PrintN ( int N );

int main ()
{
    int N;

    scanf("%d", &N);
    PrintN( N );

    return 0;
}


void PrintN (int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		printf("%d\n",i);
	}
}