def find_map(x, y, z, n):
    board[y][x] = '0'
    if  y < n - 1 and board[y+1][x] == '1':
        num[z] += 1
        find_map(x, y+1, z, n)
    if x < n - 1 and board[y][x+1] == '1':
        num[z] += 1
        find_map(x+1, y, z, n)
    if x > 0 and board[y][x-1] == '1':
        num[z] += 1
        find_map(x-1, y, z, n)
    if y > 0 and board[y-1][x] == '1':
        num[z] += 1
        find_map(x,y-1, z, n)


N = int(input())
board = [[0]*N]*N
num = [0]
Z = 0

for y in range(N):
    board[y]= list(input())


for Y in range(N):
    for X in range(N):
        if board[Y][X] == '1':
            find_map(X, Y, Z, N)
            num[Z] += 1
            Z += 1
            num.append(0)

num.pop()

num.sort()

print(Z)
for i in range(Z):
    print(num[i])