#include <stdio.h>

char inout[200001];
int stack[100001]; 
int idx = 0;

void input(int start, int last);
int check(int start, int last);

int main() {
    int n, num;
    int set;
    
    scanf("%d", &n);
    
    scanf("%d", &num);
    
    input(1, num);
    set = num;
    
    for(int i = 1;i < n; i++)
    {
        scanf("%d", &num);
        
        if(num < set)
        {
            if(check(num, set))
            {
                stack[num] = 0;
                inout[idx++] = '-';
            }
            else
            {
                printf("NO");
                return 0;
            }
        }
        else
        {
            input(set+1, num);
            set = num;
        }
    }
    
    for(int i = 0; i < idx; i++)
    {
        printf("%c\n", inout[i]);
    }


    return 0;
}

void input(int start, int last)
{
    for(int i = start; i <= last; i++)
    {
        inout[idx++] = '+';
        stack[i] = 1;
    }
    
    inout[idx++] = '-';
    stack[last] = 0;
}

int check(int start, int last)
{
    for(int i = start + 1; i < last; i++)
    {
        if(stack[i] == 1)
        {
            return 0;
        }
    }
    return 1;
}