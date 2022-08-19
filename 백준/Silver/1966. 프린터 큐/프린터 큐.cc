#include <stdio.h>

int que[510000];

int main()
{
    int n, m, t, s;
    int now_index;
    int check;
    scanf("%d", &t);

    while(t--)
    {
        
        scanf("%d %d", &n, &m);

        for(int i = 0 ; i < n; i++)
        {
            scanf("%d", &que[i]);
        }

        check = 1;
        now_index = m;

        for(int i = 0 ; i < n; i++)
        {   
            for(s = i+1; s < n; s++)
            {
                if(que[i] < que[s])
                {
                    if(i == now_index)
                    {
                        now_index = n;
                    }
                    que[n] = que[i];
                    n++;
                    break;
                }
            }

            if(s == n)
            {
                if(i == now_index)
                {
                    printf("%d\n", check);
                    break;
                }
                check++;
            }
        }
    }

    return 0;
}