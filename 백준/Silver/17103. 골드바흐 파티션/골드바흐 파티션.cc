#include <stdio.h>

int power[1000001];

void make_sosu()
{
    for(int i = 4; i < 1000000; i += 2)
    {
        power[i] = 1;
    }
    for(int i = 3; i < 1001; i += 2)
    {
        if(power[i] == 0)
        {
            for(int s = i*2; s < 1000000; s += i)
            {
                power[s] = 1;
            }
        }
    }
}

int main()
{
    int T, n, count;
    
    make_sosu();
    scanf("%d", &T);

    while (T--)
    {
        scanf("%d", &n);
        if(n == 4)
            count = 1;
        else
            count = 0;
        for(int i = 3; i <= n/2; i += 2)
        {
            if(!power[i])
            {
                if(!power[n-i])
                    count++;
            }
        }
        printf("%d\n", count);
    }
}