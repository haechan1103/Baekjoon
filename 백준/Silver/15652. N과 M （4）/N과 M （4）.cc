#include <stdio.h>

int stack[8];
int n, m;

void print(int, int);

int main()
{    
    scanf("%d %d", &n, &m);

    print(0, 1);
}

void print(int i, int num)
{
    if(i == m)
    {
        for(int i = 0 ; i < m; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
        return;
    }
    for(int s = num; s <= n; s++)
    {
        stack[i] = s;
        print(i+1, s);
    }
}
