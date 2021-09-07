def series():
    temp = 100000
    for i in range(6):
        for j in range(6):
            for k in range(6):
                if i%3 == j%3 or j%3 == k%3 or k%3 == i%3: continue
                row =    widht[i] + widht[j] + widht[k]
                col =    max(height[i], height[j], height[k])
                temp =   min(temp, (row*row)+(col*col))

    return temp

def pile():
    temp = 100000
    for i in range(6):
        for j in range(6):
            for k in range(6):
                if i%3 == j%3 or j%3 == k%3 or k%3 == i%3: continue
                row =    max(widht[i] + widht[j], widht[k])
                col =    max(height[i], height[j]) + height[k]
                temp =   min(temp, (row*row)+(col*col))

    return temp

widht  = [0]*6
height = [0]*6

for i in range(3):
    w, h = map(int, input().split())

    widht[i]    = w
    height[i]   = h
    widht[i+3]  = h
    height[i+3] = w

print(min(pile(), series()))

"""
박스가 3개 밖에 없어서 완전 탐색으로도 가능한 문제였던 것 같다.
"""
