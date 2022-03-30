# Dynamic Programming
---
> 동적 계획법은 세계 2차 대전 당시, 미국의 전략 계산 과정에서 도출된 알고리즘이다.  
> 공격과 방어에 최적인 무기의 무게는 어느 정도인지 등을 계산하며 등장했다.  
> 이러한 연구는 __Operations Research__ 라고 하는데, 산업공학의 대표적 연구 분야 중 하나이다.  

## 동적 계획법의 원리
- 주어진 문제 X보다 약간 더 쉬운 문제 Y를 풀 수 있다면?
  - Y의 결과 답을 모아서, X의 답을 좀 더 쉽게 찾을 수 있다.
  - ex) 부산에서 강릉까지 가는 가장 빠른 길? 
    - 강릉에 인접한 4개 도시까지 가는 가장 빠른 길을 알면, 부산까지도 알 수 있다!  

### 동적 계획법을 위한 3가지 준비물
  - 동적 계획 공식 (점화식)
  - 초기 조건
  - 적당한 크기의 Table 

### 동적 계획법의 시간 복잡도
- Space complexity : Table의 크기
- Time complexity : Table의 모든 Entry를 채우는 데에 걸리는 시간.

## Example : 스키장 스키 대여 문제
> 스키장에서 장비를 대여해서 즐기려고 한다.  
> 대여 일 수와 가격은 아래와 같으며, 날짜에 'O' 표시가 된 날만 스키를 탈 수 있다.   

![image](https://user-images.githubusercontent.com/71700079/160738514-54ebf0f8-5476-4b44-a352-46f075053648.png)
![image](https://user-images.githubusercontent.com/71700079/160738547-40abece3-143b-4400-acd7-06770eb63b7c.png)  

- 날짜를 하루씩 옮겨가며 1일권, 3일권, 7일권 중에 가장 돈이 적게 드는 입장권을 배열에 저장하며 푼다.
  - 중요한 것은 1일권, 3일권, 7일권의 Count를 현재 날짜로부터 뒤로 세는 것.
  - 따라서 점화식은 min(DP[i-1] + 3, DP[i-3] + 7, DP[i-7] + 10)가 된다.

## 대표 Example : Knapsack
> 물건들에 각각 최대 무게와 가치가 있을 때, 해당 최대 무게에 최대 이윤은 얼마인가?에 대한 문제이다.  
> 이것 또한 DP의 대표적인 문제!  

![image](https://user-images.githubusercontent.com/71700079/160741146-cd4af94d-12ab-48f8-87fa-268fe1044668.png)  
- 위의 문제는 가로 행의 물건 무게를 합쳐 세로 열의 숫자를 만들 수 있는지에 대한 문제이다.
- 물건이 n개라고 생각하고 DP 식을 구해보면, n번째 물건을 담는 경우와 안담는 경우로 나눌 수 있을 것이다.
  - n번째 물건을 담는 경우 : ```DP[n-1][j - n] == 1```이면, ```DP[n][j]``` 또한 1이다.
  - n번째 물건을 담지 않는 경우 : 바로 이전 물건, ```DP[n-1][j] == 1```이면 ```DP[n][j]``` 또한 1이다.

## Floyd-Warshall Algorithm
> 최단 경로를 구하는 문제에 적용되는 알고리즘이다.  

- 원래 최단 경로를 구할 때에는 Dijkstra Algorithm이 이용된다.
  - 하지만 Dijkstra는 Edge의 Weight의 합이 음수가 될 경우는 쓸 수가 없는 Algorithm이 된다!
  - Theta(N^3)의 시간 복잡도를 가진다.
- ```DP(k)[i][j]``` 의 배열을 만들어 구한다.
  - i부터 j 사이의 vertex들의 index는 k를 넘어갈 수 없다.
  - k가 0일 경우는, ```weight(i, j)```가 된다.
  - k가 무한대일 경우는, 연결이 되어있지 않은 것!
  - ```DP(0)[i][j]``` 부터 차례차례 구해나간다.
  - 그 식은 ```min(DP(k-1)[i][k] + DP(k-1)[k][i], DP(k-1)[i][j])```이 된다.
  - 결국 Vertex가 N개일 때 ```D(N)[i][j]``` Matrix를 구해내는 데에 목적이 있다.

## Game에서 이용하는 방법
- 완전 정보 게임
  - ex) 바둑, 오목, IQ Puzzle
- 확률 게임
  - ex) 고스톱, 포커, 야구
- Game Tree를 구성해서 해결하는 것이 일반적인 해법!

### Example : 바둑돌 게임  
![image](https://user-images.githubusercontent.com/71700079/160313380-fcdb8561-bcc4-45ae-a37f-28f6312fefef.png)  
- GAME 1
  - K개의 바둑돌이 있다.
  - 자신의 차례에 1개, 2개, 혹은 3개의 돌을 가져갈 수 있다.
  - 자신의 차례에 정해진 동작이 불가하면 그 사람이 진 것이다.  
  ![image](https://user-images.githubusercontent.com/71700079/160313619-88f52c3f-d231-462f-b291-3f1d0b295471.png)  
  - 이는 Game Tree에서 자신의 아래 Node (K-1, K-2, K-3) 3개 모두가 First일 경우, 자신은 Second.
    - Node중 하나라도 Second일 경우, 자신은 First가 된다.

- GAME 2
  - GAME 1과는 다르게 1개, 3개, 4개의 돌을 가져갈 수 있다.
  - 결국 마찬가지로 Game Tree에서 자신의 아래 Node (N-1, N-3, N-4) 3개 모두가 First일 경우, 자신은 Second.
    - Node중 하나라도 Second일 경우, 자신은 First.

- Game 3
  - 자신의 차례에 한번에 1개, 3개, 4개의 돌을 가져갈 수 있다.
  - 하지만 앞 사람이 가져간 만큼 다음 사람이 가져갈 수는 없다!(중복 금지)  
  ![image](https://user-images.githubusercontent.com/71700079/160314425-067cdd46-443e-4474-bb2d-acc84ebffbda.png)  

## LCS : 최장 공통 서열
> 두 문자열 사이의 가장 긴 공통된 부분 순서들을 구하는 문제이다.  
> 대표적인 DP 문제.  
