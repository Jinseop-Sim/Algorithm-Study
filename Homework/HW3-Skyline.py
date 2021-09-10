def make_build(num):
    for _ in range(num):
        building.append(list(map(int, input().split())))
    building.sort()

def endpoint(num):
    global end
    for i in range(num):
        if(end < (building[i][0] + building[i][2])): end = building[i][0] + building[i][2]

def make_coord(num):
    for i in range(num):
        for j in range(building[i][2]):
            height = building[i][1]
            if visit[building[i][0] + j]:
                if height > coord[building[i][0] + j]: coord[building[i][0] + j] = height
                else:                                  continue
            coord[building[i][0] + j] = height
            visit[building[i][0] + j] = 1

    print(coord)

def print_sky():
    height = coord[start]
    print(start, end = " ")
    print(height, end = " ")
    cnt = 0
    for i in range(start, len(coord)):
        if height != coord[i]:
            print(cnt, end=" ")
            print(coord[i] - height, end = " ")
            cnt = 0
            height = coord[i]
        cnt += 1

end = 0
building = []
skyline = []

n = int(input())
make_build(n)
start = building[0][0]

endpoint(n)
visit = [0]*(end+1)
coord = [0]*(end+1)

make_coord(n)
print_sky()
