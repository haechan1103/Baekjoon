#include <stdio.h>

int main(){
    int a, b, v, d;

    scanf("%d %d %d", &a ,&b, &v);

    v = v - a;
    a = a - b;
    if(v%a == 0)
        d = v/a + 1;
    else
        d = v/a + 2;
    printf("%d", d);    
}