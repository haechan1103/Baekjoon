#include <stdio.h>

int sq(int a)
{
    int n = 1;
    for(int i = 0; i < a; i++)
    {
        n *= 2;
    }

    return n;
}

int main()
{
    int n, r, c, num;
    int x1, x2, y1, y2;
    int count = 0;
    scanf("%d %d %d", &n, &r, &c);

    x1 = y1 = 0;
    x2 = y2 = sq(n);

    for(int i = n; i > 0; i--)
    {
        num = sq(2*i - 2);
        if(r < (y2 + y1)/2){
            if(c < (x2 + x1)/2){
                count += 0;
                y2 = (y2 + y1)/2;
                x2 = (x2 + x1)/2;
            }
            else{
                count += num;
                y2 = (y2 + y1)/2;
                x1 = (x2 + x1)/2;
            }
        }
        else{
            if(c < (x2 + x1)/2){
                count += num * 2;
                y1 = (y2 + y1)/2;
                x2 = (x2 + x1)/2;
            }
            else{
                count += num * 3;
                y1 = (y2 + y1)/2;
                x1 = (x2 + x1)/2;
            }
        }
    }

    printf("%d", count);
}