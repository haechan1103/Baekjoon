    #include <stdio.h>

    void multiply();
    void power(long long);

    long long arr1[2][2];
    long long arr2[2][2];
    long long temp[2][2];

    int main()
    {

        unsigned long long a, b, A, B, S;

        scanf("%lld %lld", &a, &b);

        arr1[0][0] = arr2[0][0] = 1;
        arr1[0][1] = arr2[0][1] = 1;
        arr1[1][0] = arr2[1][0] = 1;
        arr1[1][1] = arr2[1][1] = 0;

        a += 1;
        b += 2;
        power(a-1);
        A = arr1[0][0];
        arr1[0][0] = arr2[0][0] = 1;
        arr1[0][1] = arr2[0][1] = 1;
        arr1[1][0] = arr2[1][0] = 1;
        arr1[1][1] = arr2[1][1] = 0;
        power(b-1);
        B = arr1[0][0];
        if(B > A)
        {
            printf("%lld", B-A);
        }
        else
        {
            arr1[0][0] = arr2[0][0] = 1;
            arr1[0][1] = arr2[0][1] = 1;
            arr1[1][0] = arr2[1][0] = 1;
            arr1[1][1] = arr2[1][1] = 0;

            printf("%lld", (B - A + 1000000000)%1000000000);
        }
    }

    void copy()
    {
        arr1[0][0] = temp[0][0];
        arr1[0][1] = temp[0][1];
        arr1[1][0] = temp[1][0];
        arr1[1][1] = temp[1][1];
    }

    void multiply1()
    {
        
        temp[0][0] = ((arr1[0][0]*arr2[0][0]) + (arr1[0][1]*arr2[1][0]))%1000000000;
        temp[0][1] = ((arr1[0][0]*arr2[0][1]) + (arr1[0][1]*arr2[1][1]))%1000000000;
        temp[1][0] = ((arr1[1][0]*arr2[0][0]) + (arr1[1][1]*arr2[1][0]))%1000000000;
        temp[1][1] = ((arr1[1][0]*arr2[0][1]) + (arr1[1][1]*arr2[1][1]))%1000000000;

        copy();
    }

    void multiply2()
    {
        temp[0][0] = ((arr1[0][0]*arr1[0][0]) + (arr1[0][1]*arr1[1][0]))%1000000000;
        temp[0][1] = ((arr1[0][0]*arr1[0][1]) + (arr1[0][1]*arr1[1][1]))%1000000000;
        temp[1][0] = ((arr1[1][0]*arr1[0][0]) + (arr1[1][1]*arr1[1][0]))%1000000000;
        temp[1][1] = ((arr1[1][0]*arr1[0][1]) + (arr1[1][1]*arr1[1][1]))%1000000000;

        copy();
    }

    void power(long long n)
    {
        if(n == 1)
        {
            return;
        }

        if(n%2 == 0)
        {
            power(n/2);
            multiply2();
        }
        else
        {
            power(n/2);
            multiply2();
            multiply1();
        }
    }