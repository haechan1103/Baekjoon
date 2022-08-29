#include <stdio.h>

int stack[8];
int n, m;

void print(int);

int main()
{    
    scanf("%d %d", &n, &m);

    print(0);
}

void print(int i)
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
    for(int s = 1; s <= n; s++)
    {
        stack[i] = s;
        print(i+1);
    }
}
