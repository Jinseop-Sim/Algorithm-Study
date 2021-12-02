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

## Representation of Tree Structure
### Parenthesis List
> 어떤 Tree가 있을 때 이를 가시적으로 보여주기 위해서 보통 괄호 리스트를 사용한다.  
- 장점 : 구현이 간단하다.
- 단점 : 동작이 매우 한정적이다.
- Example 
  - (R(P1)(P2)(P3)), 이는 Root로 R을 가지고 자식으로 P1, P2, P3의 Leaf Node를 갖는 Tree이다.
  - (a(g)(f(c(h)(j))(d))(b(e))), 이를 Tree로 그리면 아래와 같다.  
  ![image](https://user-images.githubusercontent.com/71700079/144406488-6592e50f-2e85-4a7f-a516-9dbc471a63c6.png)   

### Array + Parents Link
![image](https://user-images.githubusercontent.com/71700079/144408644-d5705649-30af-4a4c-8346-e3228993e57a.png)  
![image](https://user-images.githubusercontent.com/71700079/144408775-28fc7be3-c2c7-421d-b352-aefaa70172e5.png)  
- 위의 표(Array)와 Tree는 같은 Structure을 표현한다.
- 자식 Node까지 배열에 저장을 해두면 더 용이하게 Structure을 사용할 수 있다.
  - 보통 Struct(구조체)를 이용해서 정보들을 저장해서 Vector에 ```push_back()``` 한다.
  - 하지만 좋은 자료구조는, 모든 Index에 대해서 같은 형태를 갖는게 좋은 자료구조이다!
- 장점 : 괄호 표현법 보다는 더 많은 동작을 구현할 수 있다.
- 단점 : 괄호 표현법 보다는 구현이 어렵다.

### Real Tree
- 진짜 Tree의 모양을 내가 만드는 것이다.
- Example : 4 Degree Tree  
![image](https://user-images.githubusercontent.com/71700079/144410083-63c83873-753a-4a03-8b94-9aa8825a4d55.png)  

- 가장 보편적인 형태로 사용하는 자료 구조이다.
- 각 Node에는 부모를 가리키는 Node를 하나 더 만들어 놓았는데, 이는 Stack을 사용해서 부모를 저장한다면 필요가 없는 부분이다.

## Binary Search Tree
> 이진 탐색 트리라고 하며, 가장 흔한 형태의 트리로 Regular Tree의 일종이다.  
> Tree의 차수(자식의 최대 수)가 2로 Fixed된 트리이다.  
> 이진 탐색 트리를 주로 사용하는 이유는, Degree가 2밖에 되지 않아 구조를 만들기 편하기 때문이다.  

### Complete Binary Tree
![image](https://user-images.githubusercontent.com/71700079/144414294-e9120d10-c111-4af2-8a69-fa317e20cb70.png)  

- 위 그림과 같이 왼쪽부터 순서에 맞게 채워져 있는 BT를 Complete BT라고 한다.
- 순서에 맞지 않게 왼쪽 자식이 비었는데, 오른쪽 자식이 채워져 있거나 하면 완전 이진 트리가 될 수 없다.

### Full Binary Tree
![image](https://user-images.githubusercontent.com/71700079/144414473-c76d75ef-0598-4613-a1e5-f1362248670c.png)  

- 위 그림과 같이 빈 node 없이 모두 꽉꽉 채워진 BT를 Full BT(포화 이진 트리) 라고 한다.

### Calculate Size : Pseudo code
```C++
int tSize(int T){
  if (T == 0) return 0;
  return tSize(T.left_sub_tree) + tSize(T.right_sub_tree);
}
```
### Calculate Depth : Pseudo code
```C++
int tDepth(int T){
  if (T == 0) return 0;
  else{
    a = tDepth(T.right_sub_tree);
    b = tDepth(T.left_sub_tree);
    return (max({a, b}) + 1);
  }
```
- 모든 연산을 왼쪽 오른쪽 부트리에 Recursive하게 타고 들어가는 방식을 이용한다.

## Quad Tree  
> 특이한 형태의 트리 구조이며, 보통 이미지 파일을 압축할 때 이용하는 방식이다.  

- Example  
![image](https://user-images.githubusercontent.com/71700079/144411079-ae6e0881-5060-47f6-86f9-04bc421d004b.png)  

- 위와 같은 image가 존재한다고 가정 했을 때, 색칠 된 부분을 1로 생각한다(Bitmap).
- 그리고 좌표계와 동일하게 1 2 3 4 분면의 값을 검사해서 Tree로 만드는 것이다.
- 과정을 도식화 하면 이와 같다.
![image](https://user-images.githubusercontent.com/71700079/144411536-f20b9191-5e1c-483f-837e-e01d28cb47f9.png)  

- Quad Tree의 장점?
  - 이미지의 회전을 할 때, Bit로 일일이 다 회전시키기에는 매우 어렵다.
  - 이 때, Quad Tree의 Subtree를 Swap함으로써 이미지를 회전을 시킬 수가 있다.

## Red-Black Tree
## AVL Tree

## Equivalence of Tree?
> __Canonical Ordering(표준 정렬)__ 을 한 결과가 같으면 같은 Tree이다.
