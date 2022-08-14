#include <stdio.h>
#define Max(x,y) x > y ? x : y

int main()
{
	int n, max;
	int dp[100001];
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &dp[i]);
	}
	
	max = dp[0];
	
	for(int i = 1; i < n; i++)
	{
		if(dp[i] + dp[i-1] > 0)
			dp[i] = Max(dp[i],dp[i] +  dp[i-1]);
			
		if(max < dp[i])
			max = dp[i];
	}
	
	printf("%d", max);
}