#include <stdio.h>

int main()
{
    int a = 0,c = 0, g = 0, t = 0, num = 0;
    int la, lc, lg, lt, s, p;
    char string[1000001];

    scanf("%d %d", &s, &p);

    scanf("%s", string);

    scanf("%d %d %d %d", &la, &lc, &lg, &lt);

    for(int i = 0; i < p; i++)
    {
        if(string[i] == 'A')
        {
            a++;
        }
        else if(string[i] == 'C')
        {
            c++;
        }
        else if(string[i] == 'G')
        {
            g++;
        }
        else
        {
            t++;
        }
    }

    for(int i = p; i < s; i++)
    {
        if(a >= la && c >= lc && g >= lg && t >= lt)
        {
            num++;
        }

        if(string[i] == 'A')
        {
            a++;
        }
        else if(string[i] == 'C')
        {
            c++;
        }
        else if(string[i] == 'G')
        {
            g++;
        }
        else
        {
            t++;
        }

        if(string[i - p] == 'A')
        {
            a--;
        }
        else if(string[i - p] == 'C')
        {
            c--;
        }
        else if(string[i - p] == 'G')
        {
            g--;
        }
        else
        {
            t--;
        }
    }
    
    if(a >= la && c >= lc && g >= lg && t >= lt)
    {
        num++;
    }

    printf("%d", num);

    return 0;
}