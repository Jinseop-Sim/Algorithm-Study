tile = list(map(int, input().split()))[:-1]

iter = 0
ans = []
cnt = 0

while max(tile) != 0:
    if iter == len(tile):
        ans.append(cnt)
        iter = 0
        cnt = 0

    if tile[iter] != 0:
        tile[iter] -= 1
        cnt += 1

    iter += 1

ans.append(cnt)
ans.append(0)
print(*ans)

"""
타일링 과제였다.
가로로 9 7 6 2 2 1 이렇게 놓은 타일을 세로로 생각했을 때 몇 장인가를 세는 코드이다.
위의 예시에 대한 출력은 6 5 3 3 3 3 2 1 1 이 된다.
"""
