n = int(input())
room = []

for _ in range(n):
    a, b = list(map(int, input().split()))
    room.append([a,b])

room.sort()
room.sort(key=lambda x:x[1])


t = 0
time = 0

for i in room:
    if i[0] >= time:
        time = i[1]
        t += 1
print(t)