#include <stdio.h>

int stack[8];
int check[8];
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
        if(!check[s - 1])
        {
            stack[i] = s;
            check[s - 1] = 1;
            print(i+1);
            check[s - 1] = 0;
        }
    }
}
