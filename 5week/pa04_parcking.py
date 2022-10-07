k, n = map(int, input().split())

park = list()
for i in range(n):
    car = int(input())
    if car > 0 :
        if 0 in park :
            park[park.index(0)] = car
        else:
            park.append(car)
    else :
        car = car * -1
        if car in park :
            park[park.index(car)] = 0

for i, n in enumerate(park) :
    if n != 0 : print(f"{i+1} {n}")