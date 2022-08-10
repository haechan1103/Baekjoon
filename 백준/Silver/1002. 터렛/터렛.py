R = int(input())
for i in range(0,R):
    x1,y1,r1,x2,y2,r2 = map(int, input().split())
    len_ = (x1-x2)**2 + (y1-y2)**2
    Len = len_**0.5          
    if Len == 0:
        if r1 == r2 and r1 != 0:
            print(-1)
        else:
            print(0)
    elif (r1 + r2) > Len:
        if r1 > r2:
            if Len < r1:
                if r1 < r2 + Len:
                    print(2)
                elif r1 == r2 + Len:
                    print(1)
                else:
                    print(0)
            else:
                if Len < r2 + r1:
                    print(2)
                else:
                    print(0)
                
        else:
            if Len < r2:
                if r2 < r1 + Len:
                    print(2)
                elif r2 == r1 + Len:
                    print(1)
                else:
                    print(0)
            else:
                if Len < r1 + r2:
                    print(2)
                else:
                    print(0)
    elif (r1 + r2) == Len:
        print(1)
    else:
        print(0)