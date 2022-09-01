#include <stdio.h>
#include <stdlib.h>

int sdoku1[9][10];
int sdoku2[9][10];
int sdoku3[9][10];
int map[9][9];

void find(int, int);

int main()
{
    for(int y = 0; y < 9; y++)
    {
        for(int x = 0; x < 9; x++)
        {
            scanf("%d", &map[y][x]);
            sdoku1[y][map[y][x]] = 1;
            sdoku2[(y/3)*3+x/3][map[y][x]] = 1;
            sdoku3[x][map[y][x]] = 1;
        }
    }

    find(0,0);
}

void find(int x, int y)
{
    int X = x;
    int s;
    for(int Y = y; Y < 9; Y++)
    {
        for(; X < 9; X++)
        {
            if(map[Y][X] == 0)
            {
                for(s = 1; s < 10; s++)
                {
                    if(sdoku1[Y][s] == 0 && sdoku2[(Y/3)*3+X/3][s] == 0 && sdoku3[X][s] == 0)
                    {map[Y][X] = s;
                        sdoku1[Y][s] = sdoku2[(Y/3)*3+X/3][s] = sdoku3[X][s] = 1;
                        if(Y != 8 || X != 8)
                        {
                            find(X + 1, Y);
                            map[Y][X] = 0;
                            sdoku1[Y][s] = sdoku2[(Y/3)*3+X/3][s] = sdoku3[X][s] =0;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                if(s == 10)
                {
                    return;
                }
            }
            if(Y == 8 && X == 8)
            {
                for(int Y = 0; Y < 9; Y++)
                {
                    for(X = 0; X < 9; X++)
                    {
                        printf("%d ",map[Y][X]);
                    }
                    printf("\n");
                }
                exit(0);
            }
                    
        }
        X = 0;
    }
}