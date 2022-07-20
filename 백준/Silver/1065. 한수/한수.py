n = int(input())

if n < 100:
    print(n)
else:
    count = 0
    for num in range(111, n+1):
        num = str(num)
        n1 = int(num[0])
        n2 = int(num[1])
        n3 = int(num[2])

        if n1 - n2 == n2 - n3:
            count += 1
    print(99+count)