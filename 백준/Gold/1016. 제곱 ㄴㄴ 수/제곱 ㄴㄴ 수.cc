#include <stdio.h>

int prime[1000001];
int check[1000001];

void make_prime();

int main() 
{
    long long a,b;
    long long power, start, mod;
    int count;

    
    scanf("%lld %lld", &a, &b);
    count = b - a + 1;
    
    make_prime();

    mod = a%4;
    if(mod != 0)
        start = a + 4 - mod;
    else
        start = a;
        
    for(long long i = start; i <= b; i += 4)
    {
        check[i - a] = 1;
        count -= 1;
    }
    
    for(long long i = 3; i < 1000000; i += 2)
    {
        if(prime[i] == 0)
        {
            power = i*i;
            mod = a % power;
            start = a;
            if(mod != 0)
                start += power - mod;
            
            for(long long s = start; s <= b; s += power)
            {
                if(check[s - a] == 0)
                {
                    check[s - a] = 1;
                    count -= 1;
                }
            }
            
        }
    }
    
    
    printf("%d", count);
}

void make_prime()
{
    prime[0] = 1;
    prime[1] = 1;
    for(int i = 4; i < 1000001; i += 2)
    {
        prime[i] = 1;
    }
    for(int i = 3; i < 1001; i += 2)
    {   
        if(prime[i] == 0)
        {
            for(int s = i+i; s < 1000000; s += i)
            {
                prime[s] = 1;
            }
        }
    }
}