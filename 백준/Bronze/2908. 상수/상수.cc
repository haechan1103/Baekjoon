#include <stdio.h>

int main()
{
    int a, b;
    char A[4], B[4];

    scanf("%s %s", A, B);

    a = (A[0]-48) + (A[1]-48)*10 + (A[2]-48)*100;
    b = (B[0]-48) + (B[1]-48)*10 + (B[2]-48)*100;

    if(a>b)
    {
        printf("%d", a);
    }
    else
    {
        printf("%d", b);
    }
}