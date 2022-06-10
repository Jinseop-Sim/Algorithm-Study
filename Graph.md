# Graph
---
## Graph?
> Node(vertex)와 Edge로 구성된 수학적 자료구조이다.  
> 자료들간의 관계를 표현할 수 있는 가장 일반적인 자료구조이다.  
> 보통 순서(앞 뒤)가 없는 구조이므로 매우 유연하게 자료를 담을 수 있지만, 그만큼 복잡하다.  

## Represent Graph
- 그래프의 표현 방식에는 보통 3가지가 있다고 한다.
  - 인접 행렬(Adjacent Matrix)
  - 인접 리스트(Adjacent List)
  - 간선 리스트(Edge List)

## Graph Search
> Graph의 탐색 방식에는 대표적으로 DFS, BFS 두 가지가 존재한다.  

### BFS(Breadth First Search)
> 자료구조로 Queue를 이용하는 너비 우선 탐색이다.  
> 물결파가 퍼져나가듯이 인접한 모든 Node들을 다 확인하면서 지나가는 방식이기 때문에,  
> 보통 최단거리를 구해야 하는 문제에서 유용하게 쓰이는 기법이다.  

- Tree 구조를 예시로 생각해보면 그 동작은 아래와 같다.  
![bfs](https://user-images.githubusercontent.com/71700079/144698194-9687b98c-508a-4f52-9c03-1335e3fdc79f.gif)  


### DFS(Depth First Search)
> 자료구조로 Stack을 이용하는 깊이 우선 탐색이다.  
> BFS와는 다르게 하나의 경로를 쭉 파고 들어가기 때문에,  
> 보통 특정 경로를 지나야만 하는 문제에서 유용하게 쓰이는 기법이다.  
> Stack으로 구현을 하기도 하지만 Recursive하게 구현도 가능하다.  

- Tree 구조를 예시로 생각해보면 그 동작은 아래와 같다.  
![img](https://user-images.githubusercontent.com/71700079/144698180-dfbe13ad-a1cb-4afe-9dbc-77b2cae1edca.gif)  

## Spanning Tree
### Minimum Spanning Tree
- Kruskal's Algorithm(Greedy)
  1. 모든 Edge를 가중치별로 정렬한다.
  2. 가중치의 값이 가장 작은 Edge부터 하나씩 추가해서 Graph를 구성한다.
  3. 구성 과정에서 Cycle이 생기면 그 edge는 버린다.
  4. 추가된 edge가 V-1개 이면, 작업을 중단하고 결과를 알린다.
- Prim's Algorithm
  1. 한 점에서 가장 짧은 Edge를 선택해서 이를 중간 MST라고 생각한다.
  2. MST에 연결된 후보 edge들 중에서 가장 작은 weight의 edge를 추가한다.
- Solin's Algorithm
  1. 일종의 Parallel Time 알고리즘이다.
  2. 각 {Node, Forest}는 자신의 이웃 중에서 가장 짧은 Edge를 고른다.
  3. 이 작업중에서 Edge가 Cycle을 만들면 버린다.
## Shortest Path Problem
### Dijkstra Algorithm
> Dijkstra(다익스트라) 알고리즘은, Shortest Path를 구하는데에 가장 널리 사용되는 방식이다.  
- Source에서 부터 Shortest Path Tree를 만들어 나가는 방식이다.
  1. 먼저 Source를 하나 정한다.
  2. 그 다음 후보 Edge 끝에 걸친 Vertex 들을 모두 PQ에 집어 넣는다.
  3. PQ 중 top은 Cost가 가장 작은 Vertex가 될 것. ```pop()``` 한다.
  4. 다음 후보 Edge들을 넣을 때, Pop한 Vertex의 Cost를 더하고 넣는다.
  5. 목적지 Vertex가 나올 때 까지 반복. 

### Bellman Ford Algorithm

## Backtracking
> 되추적법.  
### Bound & Branch
> 분기 한정.  

## Strongly Connected?
> Strongly Connected Directed Graph란 무엇일까?  

- Graph 전체의 Vertex 집합에서, 어떤 두 Vertex u, v를 찍었을 때 (u, v), (v, u) 모두 길이 존재하는 경우 우리는 Strongly Connected라고 한다.

### SCC(Strongly Connected Component)
> Strongly Connected Component란 무엇일까?  

- 이번엔 Graph 전체가 아닌, Graph 내의 어떤 Vertex 집합이다.
- 어떤 두 Vertex u, v를 찍었을 때 (u, v), (v, u) 모두 길이 존재하는 경우, 그 집합을 Strongly Connected Component라고 한다.

### Kosaraju Algorithm
> 어떤 Graph가 주어졌을 때, 그 Graph 내의 SCC가 몇 개인지  
> 또는 어떤 Vertex의 집합인지를 구할 수 있는 Algorithm이다.  

![image](https://user-images.githubusercontent.com/71700079/173041818-c93a378d-a7a7-4875-8ff0-608f23cfca2a.png)  
1. 위와 같은 Graph가 존재할 때, 1번부터 DFS를 시행해보자.
2. 이후, 종료되는 순서대로 Stack에 집어 넣는다. ( 3, 2, 6, 5, 4, 1 )   
![image](https://user-images.githubusercontent.com/71700079/173042122-b0124a51-97bc-413f-bc07-b7d50b38a223.png)  
3. 위와 같이 역방향 Graph를 그린다.
4. 이후 Stack의 Top(가장 늦게 끝났던 Vertex)부터 역방향 Graph에서 다시 DFS를 돌린다.
5. 그럼 연결 요소들이 여러개 등장할텐데, 그것들이 각각 SCC(Strongly Connected Component)가 된다.  
![image](https://user-images.githubusercontent.com/71700079/173042283-ac3a33b7-7637-4748-ad97-c2ad5acf2fda.png)  
