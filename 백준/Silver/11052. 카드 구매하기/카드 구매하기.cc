#include <stdio.h>
#define max(x,y) x>y? x : y

int card[1001];
int dp[1001];

int main()
{
    int n, m;

    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &card[i]);
    }

    dp[1] = card[1];

    dp[2] = max(card[1]*2, card[2]);

    m = max(dp[1],dp[2]);
    for(int i = 3; i <= n; i++)
    {
        dp[i] = card[i];
        
        for(int s = 1; s <= i/2; s++)
        {
            dp[i] = max(dp[i], dp[s]+dp[i-s]);
        }
        m = max(dp[i], m);
    }

    printf("%d", m);
    
    return 0;
}