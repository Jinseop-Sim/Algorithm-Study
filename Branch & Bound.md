# Branch & Bound
---
> 분기 한정법.  
> Backtracking에서 더욱 발전되어서 재귀를 빠른 시간안에 줄일 수 있는  
> 분기한정법에 대해서 알아보자.  

## Branch & Bound?
> ## 만약 우리가 무인도에서 정글을 헤쳐 나간다고 생각해보자.  
- 우리는 현재 지도를 들고 있지 않으며, 야자나무까지 가는 가장 빠른 길을 찾아야 한다.
- 만약 Backtracking 이었다면, 길을 가보고 안되면 되돌아나오는 식으로 탐색을 할 것이다. (Exhaustive)
  - 하지만 Branch & Bound의 경우엔?
  - State Tree를 그려나가면서, 각 점에 대해서 가장 가능성 있는 길로 가야한다! How?
    - 야자수까지 직선거리가 가장 짧은 길을 선택한다. (Priority Queue의 이용, 후보들을 계속 관리해주는 것이 중요!)
  - Branching : 가능성 있는 Node들로 가지를 뻗는 작업을 의미한다.
    - Priority Queue를 통해서 제일 가능성 있는 Node부터 꺼내서 확인한다.
    - 이 때, 그 Node가 더 이상 진행할 수 없는 Node라고 판단되면 __Bound(Pruning)__ 시킨다고 한다.

### Sequence
1. 초기해를 구한다. (최적일 필요 없이 그냥 답, Greedy하게 구한다.)
2. 더 나은 답이 나오면 해를 Update하며, 그 해보다 작은(큰) Node들은 탐색하지 않는다.(Bound)
  - 즉 더 나은 답이 새로운 Bound가 되는 것!

### Backtracking vs Branch & Bound
- Backtracking
  - 기계적인 방문순서를 가지며, Solution의 상태와 상관이 없다.
  - Searching space에 대한 관리
  - 탐색 상태를 Stack(DFS)에 저장한다.
- Branch & Bound
  - 내가 현재 가질 수 있는 최적 Solution에 따라 방문 순서가 달라진다.
  - Searching Space를 저장을 해가며 관리한다.
  - 탐색 상태는 Queue에 저장된다.
  - 물론 이 또한 완전 탐색의 일종이지만, Backtracking 보다는 좀 더 개선될 수 있다.

## Example : 6-Queen Problem
> Backtracking의 대표적인 문제인 N-Queen Problem을 B&B로 해결한다면?    

![image](https://user-images.githubusercontent.com/71700079/172051688-39dc94ea-6691-4199-87ac-1d65c03169ef.png)   
- Queen을 놓았을 때, 다른 Queen이 놓을 수 없도록 잡아먹는 공간이 몇 칸인지를 세어 본다.
  - 당연히 적을 수록 좋은 해가 될 것이며, 각 열마다의 최소 값들을 저장하며 진행한다.
- 물론 Worst Case의 경우에는 전혀 개선이 되지 않는다.

## Example : TSP
