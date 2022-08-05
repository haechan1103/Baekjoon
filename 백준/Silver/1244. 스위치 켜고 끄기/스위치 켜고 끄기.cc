#include <stdio.h>

int sc[100];
int n;

void man_change(int num);
void woman_change(int num);

int main()
{
    int N;
    int sx, num;

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &sc[i]);
    }

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &sx, &num);

        if(sx == 1)
            man_change(num);
        else
            woman_change(num - 1);
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d ", sc[i]);
        if((i+1)%20 == 0)
            printf("\n");
    }
}

void man_change(int num)
{
    for(int i = num; i <= n; i += num)
    {
        if(sc[i - 1] == 0)
            sc[i - 1] = 1;
        else
            sc[i - 1] = 0;
    }
}

void woman_change(int num)
{
    if(sc[num] == 0)
            sc[num] = 1;
        else
            sc[num] = 0;
    
    for(int i = 1; num + i < n && num >= i; i++)
    {
        if(sc[num + i] != sc[num - i])
        {
            break;
        }
        else
        {
            if(sc[num + i] == 1)
            {
                sc[num + i] = sc[num - i] = 0;
            }
            else
            {
                sc[num + i] = sc[num - i] = 1;
            }
        }
    }
}