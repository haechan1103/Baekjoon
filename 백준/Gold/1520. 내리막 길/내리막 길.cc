#include <stdio.h>
#define Max(x,y) x > y ? x : y

int map[500][500];
int dp[500][500];

int DFS(int, int);
int X,Y;

int main()
{
    scanf("%d %d", &Y, &X);

    for(int y = 0; y < Y; y++)
    {
        for(int x = 0; x < X; x++)
        {
            scanf("%d", &map[y][x]);
            dp[y][x] = -1;
        }
    }

    dp[0][0] = 1;

    printf("%d", DFS(X - 1, Y - 1));

    
}

int DFS(int x, int y)
{
    if(dp[y][x] != -1)
        return dp[y][x];
    
    dp[y][x] = 0;

    if(x > 0)
    {
        if(map[y][x-1] > map[y][x])
        {
            if(dp[y][x-1] == -1)
                dp[y][x] += DFS(x-1, y);
            else
                dp[y][x] += dp[y][x-1];
        }
    }
    if(x < X - 1)
    {
        if(map[y][x+1] > map[y][x])
        {
            if(dp[y][x+1] == -1)
                dp[y][x] += DFS(x+1, y);
            else
                dp[y][x] += dp[y][x+1];
        }
    }
    if(y > 0)
    {
        if(map[y-1][x] > map[y][x])
        {
            if(dp[y-1][x] == -1)   
                dp[y][x] += DFS(x, y-1);
            else            
                dp[y][x] += dp[y-1][x];
        }
    }
    if(y < Y - 1)
    {
        if(map[y+1][x] > map[y][x])
        {
            if(dp[y+1][x] == -1)
                dp[y][x] += DFS(x, y+1);
            else
                dp[y][x] += dp[y+1][x];
        }
    }
    return dp[y][x];
}