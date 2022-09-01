#include <stdio.h>

int N[11];
int calcul[4];
int low, high, n;

void find(int, int);

int main()
{
    int idx = 0;   
    int s = 0;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &N[i]);
    }

    for(int i = 0; i < 4; i++)
    {
        scanf("%d", &calcul[i]);
    }

    high = N[0];

    for(int i = 1; i < n; i++)
    {
        if(calcul[idx] > s)
        {
            if(idx == 0)
            {
                high += N[i];
            }
            else if(idx == 1)
            {
                high -= N[i];
            }
            else if (idx == 2)
            {
                high *= N[i];
            }
            else
            {
                high /= N[i];
            }
            s++;
        }
        else
        {
            idx++;
            i--;
            s = 0;
        }
    }
    low = high;
    find(1, N[0]);

    printf("%d\n%d", high, low);
}

void find(int i, int s)
{
    if(n == i)
    {
        if(s > high)
        {
            high = s;
        }
        if(s < low)
        {
            low = s;
        }
        return;
    }

    for(int q = 0; q < 4; q++)
    {
        if(calcul[q])
        {
            calcul[q]--;
            if(q == 0)
            {
                find(i + 1, s + N[i]);
            }
            else if(q == 1)
            {
                find(i + 1, s - N[i]);
            }
            else if(q == 2)
            {
                find(i + 1, s * N[i]);
            }
            else
            {
                find(i + 1, s / N[i]);
            }
            calcul[q]++;
        }
    }
}