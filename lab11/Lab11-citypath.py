import heapq

def dijkstra(graph, start):
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
    pq = [(0, start)]
    queue = []
    heapq.heappush(queue, [distances[start], start])

    while queue:
        current_distance, current_destination = heapq.heappop(queue)

        if distances[current_destination] < current_distance:
            continue

        for new_destination, new_distance in graph[current_destination].items():
            distance = current_distance + new_distance
            if distance < distances[new_destination]:
                distances[new_destination] = distance
                heapq.heappush(queue, [distances, new_destination])
    
    return distances

N = int(input())

m = dict()
e = list()
for i in range(N):
    str = input().split()
    m[i+1] = list(map(int, str[1:]))

for key, val in m.items():
    for k in val:
        l = list()
        if k != 0:
            if key < k :
                l.append(key)
                l.append(k)
            else :
                l.append(k)
                l.append(key)
            if l not in e: e.append(l)

E = len(e)

for _ in e:
    print(f"v1={_[0]}, v2={_[1]}")