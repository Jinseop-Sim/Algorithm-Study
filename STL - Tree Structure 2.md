# Tree Structure
---
## Height Balanced Tree(높이 균형 트리)
> 높이 균형 트리란, Tree의 높이가 불균형 할 경우 그 균형을 맞춰주는 Tree이다.  
> 이를 쓰는 이유는 Worst Case를 해결함에 있어서 용이하기 때문이다.  
- 예를 들어 Binary Search Tree가 보통 O(2logN)의 탐색 속도를 보이는데,
  - 한 쪽으로 치우쳐진 Skewed Tree가 되었을 경우 O(N)이 걸리는 Worst Case가 된다.
- 또한 Skip List와 같은 자가조직(Self-organized) 자료구조의 특성을 가진다.
- 그 종류는 아래와 같다
  - AVL Tree
  - 2-3 Tree, 2-3-4 Tree
  - Red-Black Tree
  - B-Tree(B+, B*)

### How to make proper balance?
- 트리에서 균형을 잡는 일반적인 방법
  - Randomization을 통해 추출된 데이터의 Hashing 값을 사용해서 아래와 같이 데이터의 값을 분산시킨다.  
  ![image](https://user-images.githubusercontent.com/71700079/144435743-5e3171c3-f8b3-440f-a161-892aebd43386.png)  
  
  - Buffering : 입력될 때마다 바로 넣는 것이 아닌, 몇 개씩 모였을 때(__in Buffer__) 순서를 적절히 정렬해 입력한다.

## HBT : AVL Tree
> Adelson-Velskii와 Landis가 제안한 Binary Tree 기반의 높이 균형 트리의 구조.  
> 왼쪽 부트리와 오른쪽 부트리의 차이가 1보다 커질 수 없다.  

![image](https://user-images.githubusercontent.com/71700079/144436693-bb1203c3-dc74-4085-8896-f38014f6c7cd.png)  

- h(T) : Height
- T1 : T의 왼쪽 부트리 / T2 : T의 오른쪽 부트리
- h(T) = max{h(T1), h(T2)} + 1
- 따라서 위의 그림과 같이 AVL Tree : |h(T1) - h(T2)| <= 1 for all node in T.
- Insertion, Deletion, Search : 모두 O(logN)의 탐색 시간.
- __Balance Factor__ : |h(T1) - h(T2)|

### Make Balance in AVL  

![image](https://user-images.githubusercontent.com/71700079/144438651-791e3921-7f3d-49df-81ff-4443753930f2.png)  
- 위 그림과 같이 Tree를 회전을 시켜 Balance를 맞춰줄 수 있다(LL case).
- 당연히 반대편으로 회전을 시킬 수도 있다.
- 가운데 값을 Root로 올리고, 원래 Root를 회전 방향의 자식 노드로 집어 넣는 방식이다.
- 더 자세한 원리의 이해를 돕기 위해 아래의 링크를 들어가서 공부하자.
- [AVL Tree 도식화](https://github.com/Jinseop-Sim/PNU-Algorithm-Study/blob/main/TIP/AVL%20Tree%20%EB%8F%84%EC%8B%9D%ED%99%94.md)
