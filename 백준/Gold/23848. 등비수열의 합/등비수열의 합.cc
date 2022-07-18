#include <stdio.h>


int main(){
    unsigned long long n, s, sum, print = 1, que, l;
    scanf("%lld", &n);

    que = 3;
    for(long long cal = 2; que >= 3; cal++){
        sum = 0;
        que = 0;
        for(long long z = 1; sum + z <= n; z = z*cal){
            sum = sum + z;
            que++;
            if(n%sum == 0){
               if(que <= 2)
                    continue;
                print = print*(n/sum);
                printf("%lld\n", que);
                while(que--){
                    printf("%lld ", print);
                    print = print*cal;
                }
                return 0;
            }    
        }
    }
    printf("-1");
}