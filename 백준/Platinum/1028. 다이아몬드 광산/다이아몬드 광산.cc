#include <stdio.h>

int dp[750][750];

int main()
{
    char map[750][750];
    int r,c;
    int can = 0;
    int Y, l;
    
    scanf("%d %d", &r, &c);

    for(int y = 0; y < r; y++)
    {
        scanf("%s", map[y]);
    }

    if(r >= c)
    {
        for(int i = 1; i <= (c+1)/2; i++)
        {
            l = r - 2*i + 1;
            for(int y = 0; y <= l; y++)
            {
                for(int x = i-1; x < c - i + 1; x++)
                {
                    if(dp[y][x] == i - 1)
                    {
                        for(Y = y + i - 1; Y < y + i; Y++)
                        {
                            if(map[Y][x-(y-Y)] == '0' || map[Y][x+(y-Y)] == '0')
                            {
                                break;
                            }
                        }
                        if(Y == y + i)
                        {
                            dp[y][x] = i;
                            if(can != i)
                            {
                                for(Y = y + i; Y < y + 2*i - 1; Y++)
                                {
                                    if(map[Y][x-(y+2*i-2-Y)] == '0' || map[Y][x+(y+2*i-Y-2)] == '0')
                                    {
                                        break;
                                    }
                                }
                                if(Y == y + 2*i - 1)
                                {
                                    can = i;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        for(int i = 1; i <= (r+1)/2; i++)
        {
            l = r - 2*i + 1;
            for(int y = 0; y <= l; y++)
            {
                for(int x = i-1; x < c - i + 1; x++)
                {
                    if(dp[y][x] == i - 1)
                    {
                        for(Y = y + i - 1; Y < y + i; Y++)
                        {
                            if(map[Y][x-(y-Y)] == '0' || map[Y][x+(y-Y)] == '0')
                            {
                                break;
                            }
                        }
                        if(Y == y + i)
                        {
                            dp[y][x] = i;
                            if(can != i)
                            {
                                for(; Y < y + 2*i - 1; Y++)
                                {
                                    if(map[Y][x-(y+2*i-Y-2)] == '0' || map[Y][x+(y+2*i-Y-2)] == '0')
                                    {
                                        break;
                                    }
                                }
                                if(Y == y + 2*i - 1)
                                {
                                    can = i;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d", can);
}