# Shortest Path
## Dijkstra
> 하나의 정점에서 출발했을 때, 다른 모든 정점으로의 최단 경로를 구하는 Algorithm이다.  

- DP를 활용한 대표적인 최단경로 탐색 Algorithm이다.
  - 흔히 인공위성, GPS 등에 가장 많이 사용된다.
- 간선의 가중치는 음수가 될 수 없다.
  - 따라서 현실세계에 가장 적합한 Shortest Path Algorithm이다.

### Example : Basic Dijkstra, O(N^2)
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
- 구현 Code는 아래와 같다.
```C++
#include <iostream>
#include <vector>
using namespace std;
#define INF 1000000000

int nodes = 0, edges = 0, start = 0;
vector<pair<int, int>> graph[100001]; // 연결된 node와 weight
bool visit[100001];
int dist[100001];

// 자신을 제외한 방문하지 않은 Node 중 weight이 가장 작은 Node 번호.
int which_smallest() {
    int min = INF;
    int idx = 0;

    for (int i = 0; i <= nodes; i++) {
        if (dist[i] < min && !visit[i]) {
            min = dist[i];
            idx = i;
        }
    }
    return idx;
}

void dijkstra(int start) {
    dist[start] = 0; // 자신의 거리는 0으로 초기화
    visit[start] = true; // 자신은 방문한 것으로 표시

    for (int i = 0; i < graph[start].size(); i++) {
        dist[graph[start][i].first] = graph[start][i].second;
    } // 거리 배열에, 시작 node와 연결된 모든 Node까지의 가중치 적립.

    for (int i = 0; i < nodes - 1; i++) {
        int curr_node = which_smallest();
        visit[curr_node] = true;
        // 방문하지 않은 node 중 가중치가 가장 적은 node 선택

        for (int j = 0; j < graph[curr_node].size(); j++) {
            int cost = dist[curr_node] + graph[curr_node][j].second;
            // 현재 지정된 node와 연결된 다른 node와의 거리를 더해본다.
            // ex) curr_node가 2면, 1 - 2 - 4 & 1 - 2 - 3 으로 두 번 돈다.

            if (cost < dist[graph[curr_node][j].first]) {
                dist[graph[curr_node][j].first] = cost;
                // 만약 해당 경로에 대해서 원래 dist 배열의 가중치보다 cost가 작다면,
                // 교체 한다.
                // ex) curr_node가 1 - 4 보다, 1 - 2 - 4가 더 짧은 거리이면 교체.
            }
        }
    }
}

int main() {
    cin >> nodes >> edges >> start;
    
    for (int i = 0; i < edges; i++) {
        int u = 0, v = 0, weight = 0;
        cin >> u >> v >> weight;
        graph[u].push_back(make_pair(v, weight));
    } // 입력

    fill_n(dist, 100001, INF); // 초기 Dist는 모두 INF로 초기화
    dijkstra(start);
    
    for (int i = 1; i <= nodes; i++) {
        if (dist[i] == INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }

    return 0;
}
```

### Example : Heap, O(ElogV)
- 위의 예시는 시간 복잡도가 O(N^2)이나 되는 Algorithm 이었다.
- 이번 예시는 Min Heap(Priority Queue)를 이용하여 O(ElogV)만에 끝낼 수 있는 Algorithm이다.

```C++
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1000000000

int nodes = 0, edges = 0, start = 0;
vector<pair<int, int>> graph[100001]; // 연결된 node와 weight
int dist_arr[100001];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
    min_heap.push(make_pair(0, start)); // PQ에 자기자신 삽입 (거리, node 번호).
    dist_arr[start] = 0; // 자신의 거리는 0으로 초기화

    while(!min_heap.empty()) {
        int dist = min_heap.top().first;
        int curr_node = min_heap.top().second;
        min_heap.pop();

        if (dist > dist_arr[curr_node]) continue;
        // 현재 node가 이미 처리한 node라면 무시.

        for (int i = 0; i < graph[curr_node].size(); i++) {
            int cost = dist_arr[curr_node] + graph[curr_node][i].second;
            // 현재 지정된 node와 연결된 다른 node와의 거리를 더해본다.
            // ex) curr_node가 2면, 1 - 2 - 4 & 1 - 2 - 3 으로 두 번 돈다.

            if (cost < dist_arr[graph[curr_node][i].first]) {
                dist_arr[graph[curr_node][i].first] = cost;
                min_heap.push(make_pair(cost, graph[curr_node][i].first));
                // 만약 해당 경로에 대해서 원래 dist 배열의 가중치보다 cost가 작다면,
                // dist_arr에 교체해주고, 연결된 Node들을 PQ에 삽입.
                // ex) curr_node가 1 - 4 보다, 1 - 2 - 4가 더 짧은 거리이면 교체.
            }
        }
    }
}

int main() {
    cin >> nodes >> edges >> start;
    
    for (int i = 0; i < edges; i++) {
        int u = 0, v = 0, weight = 0;
        cin >> u >> v >> weight;
        graph[u].push_back(make_pair(v, weight));
    } // 입력

    fill_n(dist_arr, 100001, INF); // 초기 Dist는 모두 INF로 초기화
    dijkstra(start);
    
    for (int i = 1; i <= nodes; i++) {
        if (dist_arr[i] == INF) cout << "INF" << '\n';
        else cout << dist_arr[i] << '\n';
    }

    return 0;
}
```

## Floyid-Warshall
> 모든 정점에서 다른 정점으로의 최단 경로를 구하는 Algorithm이다.  

![image](https://user-images.githubusercontent.com/71700079/174823499-627fdd15-abe4-44ef-b712-3d83efc5f68a.png)  

- 노드의 갯수가 N개라고 했을 때, N개에서 도달할 수 있는 모든 정점에 대해서 거리를 계산하기 때문에, Dijkstra를 N번 한다고 보면 되겠다.
- DP를 기반으로 하기 때문에, 아래와 같은 점화식을 갖는다.  
![image](https://user-images.githubusercontent.com/71700079/174823615-e2e398c4-22be-4188-891e-2b8241c1ed4a.png)  

- STEP 1
- STEP 2
- STEP 3
- STEP 4
- 시간 복잡도는 노드 수가 N개일 때, 단계마다 O(N^2)의 연산을 반복하므로, O(N^3)이 된다.

### Example : 백준 11404 - 플로이드
```C++
#include <iostream>
#include <vector>
using namespace std;
#define INF 1000000000

int nodes = 0, bus = 0;
int cities[101][101];

void make_input() {
    for (int i = 0; i < bus; i++) {
        int src, dest, d;
        cin >> src >> dest >> d;
        if(cities[src][dest] > d)
            cities[src][dest] = d;
    }
}

void init_map() { // Initialize with INFINITE
    for (int i = 1; i <= nodes; i++) {
        for (int j = 1; j <= nodes; j++) {
            if (i == j) cities[i][j] = 0;
            else cities[i][j] = INF;
        }
    }
}

void floyd_warshall() { // floyid warshall
    for (int sol = 1; sol <= nodes; sol++) {
        for (int i = 1; i <= nodes; i++) {
            for (int j = 1; j <= nodes; j++) {
                if (cities[i][sol] != INF && cities[sol][j] != INF) {
                    cities[i][j] = min(cities[i][j], cities[i][sol] + cities[sol][j]);
                }
            }
        }
    }
}

void print_answer() {
    for (int i = 1; i <= nodes; i++) {
        for (int j = 1; j <= nodes; j++) {
            if (cities[i][j] == INF) cout << 0 << " ";
            else cout << cities[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {
    cin >> nodes >> bus;

    init_map();
    make_input();
    floyd_warshall();
    print_answer();

    return 0;
}
```
