#include <stdio.h>
#define Min(x, y) x < y ? x : y

int dp[1000][3];

int main(){
    int n;
    int arr[1000][3];
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
    }
    
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];

    for(int i = 1; i < n; i++)
    {
        dp[i][0] = Min(dp[i-1][1], dp[i-1][2]);
        dp[i][0] += arr[i][0];
        dp[i][1] = Min(dp[i-1][0], dp[i-1][2]);
        dp[i][1] += arr[i][1];
        dp[i][2] = Min(dp[i-1][0], dp[i-1][1]);
        dp[i][2] += arr[i][2];
    }
    
    if(dp[n-1][0] < dp[n-1][1]){
        if(dp[n-1][0] < dp[n-1][2]){
            printf("%d", dp[n-1][0]);
        }
        else{
            printf("%d", dp[n-1][2]);
        }
    }
    else{
        if(dp[n-1][1] < dp[n-1][2]){
              printf("%d", dp[n-1][1]);
        }
        else{
             printf("%d", dp[n-1][2]);
        }
    }
}