#include <stdio.h>
#define Min(x, y) x < y ? x : y

int main()
{
    int n, m;
    int M[101];
    int C[101];
    int dp[10000000];

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &M[i]);
    }

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &C[i]);
    }

    for(int i = 0; i < M[0]; i++)
    {
        dp[i] = C[0];
    }
    for(int i = M[0]; i < m; i++)
    {
        dp[i] = -1;
    }
    for(int i = 1; i < n; i++)
    {
        for(int b = m - 1; b >= M[i]; b--)
        {
            if(dp[b-M[i]] != -1)
            {
                if(dp[b] == -1)
                {
                    dp[b] = C[i] + dp[b-M[i]];
                }
                else
                {
                    dp[b] = Min(dp[b], C[i] + dp[b-M[i]]);
                }
            }
        }
        for(int b = 0; b < M[i]; b++)
        {
            if(dp[b] == -1)
            {
                dp[b] = C[i];
            }
            else
            {
                dp[b] = Min(dp[b], C[i]);
            }
        }
        
    }
    printf("%d", dp[m-1]);
}