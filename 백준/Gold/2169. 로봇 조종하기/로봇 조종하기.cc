#include <stdio.h>
#define Max(x, y) (x) > (y) ? (x) : (y)

int map[1000][1000];
int dp[1000];
int rl[1000][2];

int main()
{
    int m, n;

    scanf("%d %d", &m, &n);

    for(int y = 0; y < m; y++)
    {
        for(int x = 0; x < n; x++)
        {
            scanf("%d", &map[y][x]);
        }
    }

    dp[0] = map[0][0];
    for(int i = 1; i < n; i++)
    {
        dp[i] = map[0][i] + dp[i-1];
    }

    for(int y = 1; y < m; y++)
    {
        rl[0][0] = dp[0] + map[y][0];
        for(int x = 1; x < n ; x++)
        {
            rl[x][0] = Max(dp[x], rl[x-1][0]);
            rl[x][0] += map[y][x];
        }

        rl[n-1][1] = dp[n-1] + map[y][n-1];

        for(int x = n-2; x >= 0; x--)
        {
            rl[x][1] = Max(dp[x], rl[x+1][1]);
            rl[x][1] += map[y][x];
        }

        for(int x = 0; x < n; x++)
        {
            dp[x] = Max(rl[x][0], rl[x][1]);
        }

    }

    printf("%d", dp[n-1]);
}