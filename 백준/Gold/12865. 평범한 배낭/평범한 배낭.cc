#include <stdio.h>
#define Max(x,y) x > y ? x : y

int dp[100001];

int main()
{
    int v[100];
    int w[100];
    int n, k;

    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &w[i], &v[i]);
    }

    for(int i = 0; i < n; i++)
    {
        for(int W = k; W >= w[i]; W--)
        {
            dp[W] = Max(dp[W], dp[W - w[i]] + v[i]);
        }
    }

    printf("%d", dp[k]);
}