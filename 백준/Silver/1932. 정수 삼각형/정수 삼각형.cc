#include <stdio.h>

int triangle[501][501];
int check[501][501];

int main()
{
    int n;
    
    scanf("%d", &n);

    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < y + 1; x++)
        {
            scanf("%d", &triangle[y][x]);
        }
    }

    for(int x = 0; x < n; x++)
    {
        check[n-1][x] = triangle[n-1][x];
    }

    for(int y = n-1; y >= 0; y--)
    {
        for(int x = 0; x <= y; x++)
        {
            if(check[y+1][x] > check[y+1][x+1])
                check[y][x] = check[y+1][x] + triangle[y][x];
            else
                check[y][x] = check[y+1][x+1] + triangle[y][x];
        }
    }

    printf("%d", check[0][0]);

    return 0;
}