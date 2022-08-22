#include <stdio.h>

int arr[5000000];

void make_prime()
{
    for(int i = 2; i < 2240; i++)
    {
        if(arr[i] == 0)
        {
            for(int s = i*2; s < 5000000; s += i)
            {
                arr[s] = 1;
            }
        }
    }
}

int move_next(int n)
{
    for(int i = n + 2; i < 5000000; i += 2)
    {
        if(arr[i] == 0)
        {
            return i;
        }
    }
}

int main()
{
    int n, num, index, idx;
    int que[1000];
    make_prime();
    
    scanf("%d", &n);

    while(n--)
    {
        index = 1;
        idx = 0;
        scanf("%d", &num);

        while(num % 2 == 0)
        {
            que[idx++] = 2;
            num /= 2;
        }

        while(arr[num] == 1)
        {
            index = move_next(index);
            while(num % index == 0)
            {
                que[idx++] = index;
                num /= index;
            }
        }

        for(int i = 0; i < idx; i++)
        {
            printf("%d ", que[i]);
        }
        if(num != 1)
        {
            printf("%d", num);
        }

        printf("\n");
    }
}