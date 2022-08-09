#include <stdio.h>
#include <string.h>
int queue[2000010];
int main(){
    int n,s;
    int f=0,r = 0;
    char a[10]; 
    scanf("%d", &n);
    while(n--){
        scanf("%s", a);
        if(strcmp(a,"push")==0){
            scanf("%d", &s);
            queue[f] = s;
            f++;
        }
        else if (strcmp(a,"pop")==0)
        {
            if(f==r){
                printf("-1\n");
                continue;
            }
            printf("%d\n", queue[r]);
            r++;
        }
        else if (strcmp(a,"size")==0)
        {
            printf("%d\n",f-r);
        }
        else if (strcmp(a,"empty")==0)
        {
            if(f==r){
                printf("1\n");
            }
            else{
                printf("0\n");
            }
        }
        else if (strcmp(a,"front")==0)
        {   
            if(f==r){
                printf("-1\n");
            }
            else{
                printf("%d\n", queue[r]);
            }
        }
        else{
            if(f==r){
                printf("-1\n");
            }
            else{
                printf("%d\n", queue[f-1]);
            }
        }       
    }
}