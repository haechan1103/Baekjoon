#include <stdio.h>

int main()
{
    long long dp[201][201];
    int n, k;

    scanf("%d %d", &n, &k);

    for(int i = 1; i < k; i++)
    {
        dp[0][i] = 1;
    }

    for(int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int s = 1; s < k; s++)
        {
            dp[i][s] = (dp[i-1][s] + dp[i][s-1])%1000000000;
        }
    }

    printf("%lld", (dp[n][k-1]));
}