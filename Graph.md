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

## Shortest Path Problem
### Dijkstra Algorithm
> Dijkstra(다익스트라) 알고리즘은, 
