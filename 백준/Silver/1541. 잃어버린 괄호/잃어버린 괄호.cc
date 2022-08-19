#include <stdio.h>

int number[50];
int number2[50];

int main()
{
    char num[51];
    int index = 0;
    int plus = 1;
    int idx = 0;
    int nmb;

    scanf("%s", num);

    for(int i = 0; num[i] != '\0'; i++)
    {
        if(num[i] > 47 && num[i] < 59)
        {
            number[index] = ((num[i] - 48) + number[index]*10);
        }
        else if(num[i] == '+')
        {
            number[++index] = -1;
            index++;
        }
        else
        {
            number[++index] = -2;
            index++;
        }
    }
    
    
    for(int i = 0; i <= index; i++)
    {
        if(number[i] == -2)
        {
            idx++;
        }
        else if(number[i] != -1)
        {
            number2[idx] += number[i];
        }
    }

    nmb = number2[0];

    for(int i = 1; i <= idx; i++)
    {
        nmb -= number2[i];
    }

    printf("%d", nmb);


    return 0;
}