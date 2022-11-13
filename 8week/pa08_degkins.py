n = int(input())

root = ''

edges = list()
for i in range(n):
    v1, v2 = input().split()
    if i == 0:
        root = v1
    edges.append([v1, v2])

edges.sort()

find1 = input()
find2 = input()

preEdge = root
cnt = 0
for k, edge in enumerate(reversed(edges)):
    if edge[1] == find1:
        find1 = edge[0]
        cnt += 1
    if edge[1] == find2:
        find2 = edge[0]
        cnt += 1

print(cnt)
