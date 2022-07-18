#include <stdio.h>

int main(){
    long long n, sum, high_num, num;

    scanf("%lld", &n);

    scanf("%lld", &high_num);
    sum = high_num;
    for(int i = 1; i < n; i++){
        scanf("%lld" ,&num);
        sum += num;

        if(high_num < num)
            high_num = num;
    }
    if(sum == 1)
        sum = 2;
    if(sum/2 < high_num)
        printf("Unhappy");
    else
        printf("Happy");

}