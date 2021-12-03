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

## Trie
> 문자열을 탐색할 때 주로 사용하는 구조인 __Trie(트라이)__ 이다.  
> String이 Key가 되는 경우에는 String에 Radix로 접근이 가능하기 때문에 이런 구조를 만들 수 있다.  
> 루트에서부터 자식으로 가면서 단어를 만들 수 있도록 문자열이 각 node에 저장이 된다.  

![image](https://user-images.githubusercontent.com/71700079/144452449-2694d622-3a41-46ac-b9ed-29e5fb29ca89.png)  

- 위와 같은 형태로 단어가 저장된다(__Radix String Tree__).
- 사전이나, 주소 찾기에 사용되는 자료구조이다.
- 일반적인 Tree는 Key 전체를 찾아 자료를 찾는 구조이지만, Trie는 Key의 일부만 보고 찾아낼 수 있다.

### Digital Search Tree
> Bit(0 and 1) 가 Key가 되는 경우의 Tree 구조이다.  

- Key의 depth번째 Bit가 0이면 왼쪽 부트리에 저장, 1이면 오른쪽 부트리에 저장한다.
- 아래와 같은 구조를 가지며, 조금 비효율적인 Trie 구조라고 보면 된다.
- Key의 길이가 길어지면 저장하는 데에 시간이 오래걸리기 때문이다.  
![image](https://user-images.githubusercontent.com/71700079/144535759-c99b2c08-978a-4b9b-8a3f-71bbad132330.png)  

### Suffix Tree
> Suffix는 접미사 라는 뜻으로, 접미사들을 Tree의 path에 저장해두고 탐색 효율을 높이는 고급 자료 구조이다.  

- Suffix : 예를 들어, Beerbox의 Suffix는 {Beerbox, eerbox, erbox, rbox, box, ox, x} 가 된다.
  - 이를 Sort(Alphabetical Order) 를 해서 배열에 저장을 해놓은 것을 보통 __Suffix Array__ 라고 부른다.
  - 뒤에서 부터 알파벳을 세어 각 Suffix의 Index를 저장해 놓으면, 편하게 단어를 찾을 수 있다.  
  ![image](https://user-images.githubusercontent.com/71700079/144537466-0e1e6acb-002b-43fd-8522-0b3bae01f4b9.png)  
  
  - 예를 들어 'rbo' 라는 단어를 검색하면 4번 index와 3번 index에 모두 존재하므로 둘이 출력될 것이다.
    - 이런 형태를 보면 주소 찾기에 응용이 가능하다는 점을 알 수 있다.
  


