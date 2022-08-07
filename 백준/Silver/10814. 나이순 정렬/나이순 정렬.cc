#include <stdio.h>

int main()
{
    int age[100001];
    int n;
    char name[50000][101];
    char name2[50001][101];

    scanf("%d", &n);

    for(int i = 0; i < n && i < 50000; i++)
    {
        scanf("%d %s", &age[i], name[i]);
    }

    for(int i = 50000; i < n; i++)
    {
        scanf("%d %s", &age[i], name2[i - 50000]);
    }

    for(int i = 1; i <= 200; i++)
    {
        for(int s = 0; s < n && s < 50000; s++)
        {
            if(age[s] == i)
            {
                printf("%d %s\n", i, name[s]);
            }
        }
        for(int s = 50000; s < n; s++)
        {
            if(age[s] == i)
            {
                printf("%d %s\n", i, name2[s - 50000]);
            }
        }
    }

    return 0;
}