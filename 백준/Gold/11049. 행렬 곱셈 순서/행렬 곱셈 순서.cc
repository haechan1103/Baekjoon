#include <stdio.h>

int matrix [501][2];
int dp [501][501];

int main()
{
    int n, min, t;

    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        scanf("%d %d", &matrix[i][0], &matrix[i][1]);
    }

    for(int i = 1; i < n; i++)
    {
        dp[2][i] = matrix[i][0]*matrix[i][1]*matrix[i+1][1];
    }

    for(int y = 3; y <= n; y++)
    {
        for(int x = 1; x <= n - y + 1; x++)
        {
            min = dp[y-1][x] + matrix[x][0]*matrix[x+y-1][0]*matrix[x+y-1][1];
            for(int m = 2; m <= y - 2; m++)
            {
                t = dp[m][x] + dp[y-m][x+m] + matrix[x][0]*matrix[x+m][0]*matrix[x+y-1][1];
                if(min > t)
                    min = t;
            }
            t = dp[y-1][x+1] + matrix[x][0]*matrix[x][1]*matrix[x+y-1][1];
            
            if(min > t)
                min = t;
            dp[y][x] = min;
        }
    }

    // for(int i = 2; i <= n; i++)
    // {
    //     for(int x = 1; x <= n - i + 1; x++)
    //     {
    //         printf("%d ", dp[i][x]);
    //     }
    //     printf("\n");
    // }
    printf("%d", dp[n][1]);
}