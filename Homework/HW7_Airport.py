import sys
from collections import deque

queue = deque()
n = int(input())
for i in range(n): queue.append(deque(map(int, sys.stdin.readline().split())))

while True:
    min = 10001
    min_idx = 0
    flag = True
    for i in range(n):
        if(queue[i][0] != 0 and min > queue[i][0]):
                min = queue[i][0]
                min_idx = i
        if(queue[i][0] != 0): flag = False
    if(flag): break

    if(queue[min_idx][0] != 0): print(queue[min_idx].popleft())