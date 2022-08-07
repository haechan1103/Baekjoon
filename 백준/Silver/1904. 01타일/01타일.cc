#include <stdio.h>

int tile[1000000];

int main()
{
    int n;
    
    scanf("%d", &n);
    tile[0] = 1;
    tile[1] = 2;

    for(int i = 2; i < n; i++)
    {
        tile[i] = (tile[i-1] + tile[i-2])%15746;
    }

    printf("%d", tile[n-1]);
}