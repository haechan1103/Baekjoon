n = int(input())

a = False
num = 0
if n < 10:
    if n%2 == 0:
        print(int(n/2))
        a = True
else:
    for i in range(n-54,n):
        temp = i
        num = i
        while i != 0:
            num = num + i%10
            i = int(i/10)
        
        if num == n:
            print(temp)
            a = True
            break

if a == False:
    print(0)