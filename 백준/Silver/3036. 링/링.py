def irreducile(a, b):
    if a > b:
        check = list(range(1,b+1))
        check.reverse()
        for i in check:
            if a%i == 0 and b%i == 0:
                return i
    else:
        check = list(range(1,a+1))
        check.reverse()
        for i in check:
            if a%i == 0 and b%i == 0:
                return i

N = int(input())

num = list(map(int, input().split()))

a = num[0]
for i in range(1,N):
    b = num[i]
    s = irreducile(a,b)
    b = int(b/s)
    print(int(a/s),"/",b, sep='')