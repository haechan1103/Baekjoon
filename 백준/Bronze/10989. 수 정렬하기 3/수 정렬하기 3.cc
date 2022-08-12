#include <stdio.h>

int num[10001];

int main()
{
    int n;
    int number;

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &number);
        num[number]++;
    }
    
    for(int i = 1; i < 10001; i++)
    {
        while(num[i])
        {
            printf("%d\n", i);
            num[i]--;
        }
    }
    return 0;
}