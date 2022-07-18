#include <stdio.h>

int arr[4000001];
void make_prime_arr();
int move_prime(int n);

int main(){
    int n, case_num, sum, s;
    make_prime_arr();

    scanf("%d", &n);

    case_num = 0;
    for(int i = 2; i <= n; i++){
        i = move_prime(i);
        sum = 0;
        for(s = i; sum < n;s++){
            s = move_prime(s);
            sum += s;
        }
        if(sum == n) case_num++;
    }
    printf("%d", case_num);
}

void make_prime_arr(){
    arr[0] = -1;
    arr[1] = -1;
    for(int i = 2; i <= 2000; i++){
        if(arr[i] == -1){
            continue;
        }
        arr[i] = i;
        for(int s = i+i; s <= 4000000; s += i){
            arr[s] = -1;
        }
    }
}

int move_prime(int n){
    while(arr[n] == -1) n++;
    return n;
}