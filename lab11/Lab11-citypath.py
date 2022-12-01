import heapq

def dijkstra(graph, start):
    distances = {node: float('inf') for node in graph}  
    distances[start] = 0  
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
              heapq.heappush(queue, [distance, new_destination])  
    
    return distances

N = int(input())

m = dict()
e = list()
for i in range(N):
    str = input().split()
    m[i+1] = list(map(int, str[1:]))
    m[i+1].pop()

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

graph = {v1: {v2 : len(m[v1])-1 for v2 in m[v1]} for v1 in m.keys()}

for _ in e:
    print(f"v1={_[0]}, v2={_[1]}")

a = list()
for i in range(1, N-1):
    a.append(max(dijkstra(graph, i).values()))

print(a)