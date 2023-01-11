#include <stdio.h>
#define Max(x,y) x > y ? x : y

int dp[301][2];

int main()
{
    int stair[300];
    
    int T;

    scanf("%d", &T);
    
    for(int i = 0; i < T; i++)
    {
        scanf("%d", &stair[i]);
    }

    dp[1][0] = stair[0];
    
    for(int y = 2; y <= T; y++)
    {
        dp[y][0] = Max(dp[y-2][0] + stair[y-1], dp[y-2][1] + stair[y-1]);
        dp[y][1] = dp[y-1][0] + stair[y-1];
    }

    printf("%d", Max(dp[T][0], dp[T][1]));

    return 0;
}