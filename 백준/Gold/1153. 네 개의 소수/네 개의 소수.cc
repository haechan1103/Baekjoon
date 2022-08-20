#include <stdio.h>

int arr[1000000] = {0,};
int t[4];

void move_arr(int n, int start,int size);
void make_prime_arr();
int move_prime_left(int n);
int move_prime_right(int n);

int main(){
    int n, a, b, i, s;

    make_prime_arr();

    scanf("%d", &n);

    
    if(n < 8){
        printf("-1");
        return 0;
    }

    if(n%2 == 0){
        a = b = n/2;
        if(a%2==1){
            a--;
            b++;
            for(i = 2;;i++){
                i = move_prime_right(i);
                if(arr[a-i] != -1)break;
            }

            for(s = 2;;s++){
                s = move_prime_right(s);
                if(arr[b-s] != -1)break;
            }
            move_arr(i, 0,0);
            move_arr(a - i, 0,1);
            move_arr(s,0 ,2);
            move_arr(b - s, 0,3);

            printf("%d %d %d %d",t[0], t[1], t[2], t[3]);
            
        }
        else{
            for(i = 2;;i = move_prime_right(++i)){
                if(arr[a-i] != -1){
                    printf("%d %d %d %d", i, i, a-i, a-i);
                    break;
                }
            }
        }
    }
    else{
        a = 2;
        i = move_prime_left(n-6);
        b = n - i - a;
        for(s = 2;;s++){
            s = move_prime_right(s);
            if(arr[b-s] != -1)break;
        }
        move_arr(a, 0,0);
        move_arr(s, 0,1);
        move_arr(b-s, 0,2);
        move_arr(i, 0,3); 

        printf("%d %d %d %d",t[0], t[1], t[2], t[3]);
    }
}

void make_prime_arr(){
    arr[0] = -1;
    arr[1] = -1;
    for(int i = 2; i <= 1000; i++){
        if(arr[i] == -1){
            continue;
        }
        arr[i] = i;
        for(int s = i+i; s <= 1000000; s += i){
            arr[s] = -1;
        }
    }
}
int move_prime_left(int n){
    while(arr[n] == -1) n--;
    return n;
}

int move_prime_right(int n){
    while(arr[n] == -1) n++;
    return n;
}

void move_arr(int n,int start, int size){
    for(int i = start; i < size; i++){
        if(t[i] > n){
            move_arr(t[i],i+1,size);
            t[i] = n;
            return;
        }
    }
    t[size] = n;
}