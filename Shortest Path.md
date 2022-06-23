# Shortest Path
## Dijkstra
> 하나의 정점에서 출발했을 때, 다른 모든 정점으로의 최단 경로를 구하는 Algorithm이다.  

- DP를 활용한 대표적인 최단경로 탐색 Algorithm이다.
  - 흔히 인공위성, GPS 등에 가장 많이 사용된다.
- 간선의 가중치는 음수가 될 수 없다.
  - 따라서 현실세계에 가장 적합한 Shortest Path Algorithm이다.

### Example
- 아래와 같은 Graph가 있다고 생각해보자.  
![image](https://user-images.githubusercontent.com/71700079/175264507-93e80c60-9106-4093-aecd-257ef6577319.png)   

1. 출발 정점을 1이라고 했을 때, 제일 처음엔 출발 노드로부터 이어진 다른 Node까지의 모든 비용을 저장한다.  
![image](https://user-images.githubusercontent.com/71700079/175264764-d0ff0d91-3562-4ac7-bb8a-6758c33735aa.png)  
  - 그럼 위와 같은 표가 만들어진다.
2. 이제 최단 경로를 찾을 수 있도록 계속 갱신을 해야한다.
  - 방문하지 않은 Node중에서 가장 비용이 적은 4번 Node부터 들려서 갱신을 해보자.
  - 4번 Node를 거쳐서 갈 수 있게 된 Node나, 더 나은 경로가 있으면 아래와 같이 갱신한다.  
  ![image](https://user-images.githubusercontent.com/71700079/175265115-9767d8c6-9e96-4404-83eb-4f9d1ba888a0.png)  
3. 남은 미 방문 Node들도 모두 돌며 똑같이 반복한다.
  - 최종적으로 갱신이 완료된 시점의 최단 경로 표는 아래와 같다.  
  ![image](https://user-images.githubusercontent.com/71700079/175265357-611242c0-10e9-48c2-ad66-81243e35673d.png)

## Floyid-Warshall
> 모든 정점에서 다른 정점으로의 최단 경로를 구하는 Algorithm이다.  

![image](https://user-images.githubusercontent.com/71700079/174823499-627fdd15-abe4-44ef-b712-3d83efc5f68a.png)  

- 노드의 갯수가 N개라고 했을 때, N개에서 도달할 수 있는 모든 정점에 대해서 거리를 계산하기 때문에, DP를 기반으로 한다.
- DP를 기반으로 하기 때문에, 아래와 같은 점화식을 갖는다.  
![image](https://user-images.githubusercontent.com/71700079/174823615-e2e398c4-22be-4188-891e-2b8241c1ed4a.png)  

- STEP 1
- STEP 2
- STEP 3
- STEP 4
- 시간 복잡도는 노드 수가 N개일 때, 단계마다 O(N^2)의 연산을 반복하므로, O(N^3)이 된다.

