#include <stdio.h>

int main()
{
    int n;
    long long low;
    long long max;
    long long dp;
    long long arr[200000];

    scanf("%d", &n);

    for(int i = 0 ; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    
    low = arr[0];
    max = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] < low)
            low = arr[i];
        
        if(max < arr[i] - low)
            max = arr[i] - low;
        
        printf("%lld ", max);
    }
}