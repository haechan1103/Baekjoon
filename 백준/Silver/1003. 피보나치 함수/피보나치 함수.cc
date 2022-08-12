#include <stdio.h>

int dp_one[41];
int dp_zero[41];

int main()
{
    int t, n;

    scanf("%d", &t);

    dp_one[0] = 0;
    dp_zero[0] = 1;
    dp_one[1] = 1;
    dp_zero[1] = 0;

    for(int i = 2; i <= 40; i++)
    {
        dp_one[i] = dp_one[i-1] + dp_one[i-2];
        dp_zero[i] = dp_zero[i-1] + dp_zero[i-2];
    }

    while(t--)
    {
        scanf("%d", &n);

        printf("%d %d\n", dp_zero[n], dp_one[n]);
    }
}