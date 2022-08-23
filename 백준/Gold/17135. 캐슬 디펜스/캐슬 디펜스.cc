#include <stdio.h>

int map[15][15];
int copy[15][15];

void move(int, int);
void map_copy(int, int);
int find_enemy(int, int, int, int, int);

int main()
{
    int n,m,d,t = 1;
    int count = 0;
    int high_count = 0;

    scanf("%d %d %d", &n, &m, &d);

    for(int y = n - 1; y >= 0; y--)
    {
        for(int x = 0; x < m; x++)
        {
            scanf("%d", &copy[y][x]);
        }
    }
    if(m >= 3)
    {
        for(int p1 = 0; p1 < m - 2; p1++)
        {
            for(int p2 = p1+1; p2 < m - 1; p2++)
            {
                for(int p3 = p2+1; p3 < m; p3++)
                {
                    count = 0;
                    t = 1;
                    map_copy(n, m);
                    for(int N = n - 1; N >= 0; N--)
                    {
                        t++;
                        count += find_enemy(N,m,p1,d,t) + find_enemy(N,m,p2,d,t) + find_enemy(N, m, p3, d, t);
                        move(N, m);
                    }

                    if(count > high_count)
                    {
                        high_count = count;
                    }
                }
            }
        }
    }
    else if(m == 2)
    {
        high_count = 0;
        map_copy(n, m);
        for(int N = n - 1; N >= 0; N--)
        {
            t++;
            high_count += find_enemy(N,m,0,d, t) + find_enemy(N, m, 1, d, t);
            move(N, m);
        }
    }
    else
    {
        high_count = 0;
        map_copy(n, m);
        for(int N = n - 1; N >= 0; N--)
        {
            t++;
            high_count += find_enemy(N,m,0,d, t);
            move(N, m);
        }
    }
    printf("%d", high_count);
}   

void move(int n, int m)
{
    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < m; x++)
        {
            map[y][x] = map[y+1][x];
        }
    }
}

void map_copy(int n, int m)
{
    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < m; x++)
        {
            map[y][x] = copy[y][x];
        }
    }
}


int find_enemy(int n, int m, int p, int d, int t)
{
    for(int D = 0; D < d; D++)
    {
        for(int x = p - D; x <= p + D && x < m; x++)
        {
            if(x < 0)
            {
                x = 0;
            }
            if(x > p)
            {
                if(D - x + p > n)
                    continue;
                if(map[D - x + p][x] == 1)
                {
                    map[D - x + p][x] = t;
                    return 1;
                }
                else if(map[D - x + p][x] == t)
                {
                    return 0;
                }
            }
            else
            {
                if(D - p + x > n)
                    continue;
                if(map[D - p + x][x] == 1)
                {
                    map[D - p + x][x] = t;
                    return 1;
                }
                else if(map[D - p + x][x] == t)
                {
                    return 0;
                }
            }
        }
    }
    return 0;
}