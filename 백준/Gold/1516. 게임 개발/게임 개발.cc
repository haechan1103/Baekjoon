#include <stdio.h>

int building_time[500];
int building_first[500][500];
int dp[500];

int find(int idx)
{
    int max = 0;

    for(int i = 1; i <= building_first[idx][0]; i++)
    {
        if(dp[building_first[idx][i]] == 0)
        {
            dp[building_first[idx][i]] = find(building_first[idx][i]);
        }
        if(max < dp[building_first[idx][i]])
            max = dp[building_first[idx][i]];
    }

    dp[idx] = max + building_time[idx];

    return dp[idx];
}

int main()
{
    
    int t, time, idx;
    
    scanf("%d", &t);

    for(int i = 0; i < t; i++)
    {
        scanf("%d", &building_time[i]);
        for(idx = 0;;)
        {
            scanf("%d", &time);
            if(time == -1)
                break;
            building_first[i][++idx] = time - 1;
        }    
        building_first[i][0] = idx;
    }
    for(int i = 0; i < t; i++)
    {
        printf("%d\n", find(i));
    }
}