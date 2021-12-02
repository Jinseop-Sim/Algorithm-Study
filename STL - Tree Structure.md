# Tree Structure
---
## What is Tree Structure?
> 트리 구조란 무엇을 말하는 것일까?  
> 나무 뿌리와 같은 형태를 가져서 Tree 구조라고 하며, 위에서 아래로 계층을 갖는 자료구조이다.  
- 동적인 동작이 필요한 자료구조들은 대부분 Tree 구조를 사용한다.
  - ex) Folder, Graphics, Database, OS.
- 이 수준부터는 변형이 매우 많으므로 STL에서 제공하지 않는다.
- Tree는 일종의 Connected Graph이지만, Cycle이 존재하지 않는다.

## Terminology
- Tree의 종류
  - Rooted Tree, Unrooted Tree : Root의 존재 여부(계층의 존재)
  - Ordered Tree, Unordered Tree : 자손의 순위가 있는지에 대한 여부
  - Directed Tree, Undirected Tree : 방향성에 대한 여부
  - Binary Tree, k-ary Tree : Rooted Tree인데, 차수가 정해져 있는 Tree.
- Taxonomy
  - Root : Rooted Tree의 제일 상위 노드.
  - Subtree : Tree의 아래에 붙어있는 Tree.
  - Parent, Child : 자신의 위가 부모, 자신의 아래가 자식.
  - Sibling : 자신의 옆 노드.
  - Depth와 Height : 밑에서 부터 0이면 높이, Root부터 0이면 깊이가 된다.
  - Leaf node : 말단 노드, 자식이 없는 노드.(Degree == 0)
  - Internal node : Root와 Leaf를 제외한 나머지 노드.
  - Degree : 가질 수 있는 자식의 최대 수.(Unrooted Tree의 경우는, 연결된 Adjacent 노드의 수를 의미한다.)
  - Least Common Ancestor(LCA) : 가장 가까운 공통 조상을 말한다. 가장 유명한 형태의 트리 탐색.

## Basic Operation of Tree
> 아래의 예시들은 손에 익어 있어야 한다!  
- A의 부모가 B인가?
- A의 자식을 모두 출력하라.
- A의 Sibling을 모두 출력하라.
- A가 속한 Tree의 Root node를 출력하라.
- A에서 B로 가는 길에 있는 모든 Node를 출력하라.
- 트리 T의 모든 leaf node를 출력하라.
- 트리 T의 모든 Node를 출력하라.
- LCA(Least Common Ancestor)

## Binary Search Tree
> 이진 탐색 트리라고 하며, 가장 흔한 형태의 트리이다.  
> Tree의 차수(자식의 최대 수)가 2로 Fixed된 트리이다.  

## Quad Tree  
> 특이한 형태의 트리 구조이며, 이미지 파일을 텍스트로 압축할 때 이용하는 방식이다.  
## Red-Black Tree
## AVL Tree
