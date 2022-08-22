#include <stdio.h>

int num[1001];
int line[10000][2];
int squence = 1;
int BFS[1001][1001];

void make_num(int);
void dfs(int, int);
void bfs(int, int, int);
void print_arr(int n);

int main()
{
    int n, m, v;

    scanf("%d %d %d", &n, &m, &v);

    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &line[i][0], &line[i][1]);
    }

    num[v] = squence++;

    dfs(v, m);

    print_arr(n);

    make_num(n);

    num[v] = squence = 1;

    bfs(v, m, n);

    printf("\n");
    print_arr(n);
}

void make_num(int n)
{
    for(int i = 1; i <= n; i++)
    {
        num[i] = 0;
    }
}

void dfs(int v, int m)
{
    int low;
    while(1)
    {
        low = 1001;
        for(int i = 0; i < m; i++)
        {
            if(line[i][0] == v)
            {
                if(line[i][1] < low && num[line[i][1]] == 0)
                    low = line[i][1];
            }
            else if(line[i][1] == v)
            {
                if(line[i][0] < low && num[line[i][0]] == 0)
                    low = line[i][0];
            }
        }

        if(low != 1001)
        {
            num[low] = squence++;
            dfs(low , m);
        }
        else
        {
            break;
        }
    }
}

void bfs(int v, int m, int l)
{
    int queue[1000];
    int low, index = 0, q = 0;
    while(1)
    {
        low = 1001;
        for(int i = 0; i < m; i++)
        {
            if(line[i][0] == v)
            {
                if(line[i][1] < low && num[line[i][1]] == 0)
                    low = line[i][1];
            }
            else if(line[i][1] == v)
            {
                if(line[i][0] < low && num[line[i][0]] == 0)
                    low = line[i][0];
            }
        }

        if(low != 1001)
        {
            num[low] = ++squence;
            queue[index++] = low;
        }
        else
        {
            if(q == l)
            {
                break;
            }
            v = queue[q++];
        }
    }
}

void print_arr(int n)
{
    for(int i = 1; i <= n; i++)
    {
        for(int s = 1; s <= n; s++)
        {
            if(num[s] == i)
            {
                printf("%d ", s);
            }
        }
    }
}