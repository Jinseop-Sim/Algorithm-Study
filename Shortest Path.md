# Shortest Path
## Dijkstra
> 하나의 정점에서 출발했을 때, 다른 모든 정점으로의 최단 경로를 구하는 Algorithm이다.  

## Floyid-Warshall
> 모든 정점에서 다른 정점으로의 최단 경로를 구하는 Algorithm이다.  
![image](https://user-images.githubusercontent.com/71700079/174823499-627fdd15-abe4-44ef-b712-3d83efc5f68a.png)  

- DP를 기반으로 하기 때문에, 아래와 같은 점화식을 갖는다.  
![image](https://user-images.githubusercontent.com/71700079/174823615-e2e398c4-22be-4188-891e-2b8241c1ed4a.png)  

- 시간 복잡도는 노드 수가 N개일 때, 단계마다 O(N^2)의 연산을 반복하므로, O(N^3)이 된다.

