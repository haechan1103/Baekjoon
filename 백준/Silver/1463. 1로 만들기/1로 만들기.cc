#include <stdio.h>
#define Min(x,y) x<y? x : y

int dp[1000001];

int main()
{
    int n;
    
    scanf("%d", &n);
    n++;

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    
    for(int i = 4; i < n; i++)
    {
        dp[i] = dp[i-1] + 1;

        if(i%2 == 0)
        {
            dp[i] = Min(dp[i], dp[i/2] + 1);
        }
        if(i%3 == 0)
        {
            dp[i] = Min(dp[i], dp[i/3] + 1);
        }
    }

    printf("%d", dp[n-1]);
}