#include <stdio.h>
int stack[10001];

int main(){
    int n, num, index = 0;
    char order[6];
    scanf("%d", &n);

    while(n--){
        scanf(" %s", order);
    
        if(order[0] == 'p' && order[1] == 'u'){
            scanf("%d", &num);
            stack[index++] = num;
        }   
        else if(order[0] == 's'){
            printf("%d\n", index);
        }
        else if(order[0] == 't'){
            if(index == 0)
                printf("-1\n");
            else
                printf("%d\n", stack[index-1]);
        }
        else if(order[0] == 'e'){
            if(index == 0)
                printf("1\n");
            else
            printf("0\n");
        }
        else{
            if(index == 0)
                printf("-1\n");
            else{
                printf("%d\n", stack[index-1]);
                index--;
            }
        }
    }
}