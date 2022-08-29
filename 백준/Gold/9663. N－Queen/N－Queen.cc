#include <stdio.h>

int map[15][15];
int count = 0;
int n;

void check_case(int);
void queen(int, int);
void reset_queen(int, int);

int main()
{
    scanf("%d", &n);

    check_case(0);

    printf("%d", count);
}

void check_case(int i)
{
    if(i == n)
    {
        count++;
        return;
    }

    for(int x = 0; x < n; x++)
    {
        if(!map[i][x])
        {
            queen(x, i);
            check_case(i + 1);
            reset_queen(x, i);
        }
    }

}

void queen(int x, int y)
{
    for(int Y = y; Y < n; Y++)
    {
        if(map[Y][x] == 0)
            map[Y][x] = y + 1;
    }
    for(int X = x + 1, Y = y + 1; Y < n && X < n; Y++, X++)
    {
        if(map[Y][X] == 0)
            map[Y][X] = y + 1;
    }
    for(int X = x - 1, Y = y + 1; Y < n && X >= 0; Y++, X--)
    {
        if(map[Y][X] == 0)
            map[Y][X] = y + 1;
    }
}

void reset_queen(int x, int y)
{
    for(int Y = y; Y < n; Y++)
    {
        if(map[Y][x] == y + 1)
            map[Y][x] = 0;
    }
    for(int X = x + 1, Y = y + 1; Y < n && X < n; Y++, X++)
    {
        if(map[Y][X] == y + 1)
            map[Y][X] = 0;
    }
    for(int X = x - 1, Y = y + 1; Y < n && X >= 0; Y++, X--)
    {
        if(map[Y][X] == y + 1)
            map[Y][X] = 0;
    }
}
