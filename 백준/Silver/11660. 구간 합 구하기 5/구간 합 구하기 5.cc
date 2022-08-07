#include <stdio.h>

int board[1024][1024];
int dp[1024][1024];

int main()
{
    int n, m, c;
    int x1, x2, y1, y2;

    scanf("%d %d", &n, &m);
    for(int x = 0; x < n; x++)
    {
        for(int y = 0; y < n; y++)
        {
            scanf("%d", &board[y][x]);
        }
    }

    dp[0][0] = board[0][0];

    for(int x = 1; x < n; x++)
    {
        dp[0][x] = dp[0][x-1] + board[0][x];
        dp[x][0] = dp[x-1][0] + board[x][0];
    }

    for(int y = 1; y < n; y++)
    {
        for(int x = 1; x < n; x++)
        {
            dp[y][x] = dp[y-1][x] + dp[y][x-1] - dp[y-1][x-1] + board[y][x];
        }
    }


    while(m--)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        x1--;
        y1--;
        x2--;
        y2--;

        if(x1 == 0 && y1 == 0)
        {
            printf("%d", dp[y2][x2]);
        }
        else if(x1 == 0)
        {
            printf("%d", dp[y2][x2] - dp[y1-1][x2]);
        }
        else if(y1 == 0)
        {
            printf("%d", dp[y2][x2] - dp[y2][x1 - 1]);
        }
        else
        {
            printf("%d", dp[y2][x2] - dp[y2][x1-1] - dp[y1-1][x2] + dp[y1-1][x1-1]);
        }
        printf("\n");
    }    

    return 0;
}