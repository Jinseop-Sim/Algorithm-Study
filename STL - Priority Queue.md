# PQ(Priority Queue)
---
## What is PQ?
> 우선순위에 따라서 Queue의 값을 뽑아 내는 특별한 Queue이다.  

## PQ in C++
> C++에서는 __Queue Header__ 에 PQ가 내장이 되어 있다.  
```C++
#include <queue>

priority_queue<int> pq; // 이게 기본적으로 정의하는 형태이다.
priority_queue<int, vector<int>, greater<int>> pq2; // 이게 완전한 PQ의 형태이다.
```
- __우선순위 큐__ 는 간단하게 내부 Elements의 Type만 선언해서 선언을 할 수도 있으며
- 그 아래의 선언문과 같이 자세하게 선언을 할 수 있다.
- ```priority_queue<타입, 내부 컨테이너, 비교 함수 구조체>``` 이런 구조를 가지고 있다.

### PQ methods
```C++
pq.push(elem) // 그냥 Queue와 같이 뒤로 원소를 집어넣는다.
pq.pop() // 우선순위에 따라 가장 우선순위가 높은(제일 앞의) 원소를 삭제한다.(반환 X)
pq.top() // 우선순위에 따라 가장 우선순위가 높은(제일 앞의) 원소를 반환한다.(삭제 X)
pq.empty() // 우선순위가 비었는지 판단한 뒤 bool로 반환한다. 보통 while문과 함께 사용된다.
pq.size() // 우선순위 큐의 크기를 반환한다.
```
## Compare Structure
> 위의 예시를 보면, __비교 함수 구조체__ 라는 말이 들어가는데,  
> 이는 PQ의 ```top()```을 정할 때의 우선순위를 정해주는 구조체가 된다.  
> 정의 형태는 아래와 같다.  

```C++
priority_queue<int, vector<int>, greater<int>> pq;
priority_queue<int, vector<int>, less<int>> pq2; // 이 2개의 선언문은 기본적인 내림차순, 오름차순의 우선순위를 결정하는 비교 구조체로 선언한 것이다.
```
- 위와 같이 기본 구조체를 넣어서 정의할 수도 있고, 아래와 같이 우리가 직접 비교함수를 만들어서 넣을 수도 있다.
```C++
struct cmp{
  bool operator()(pair<int, int> &a, pair<int, int> &b){ // 연산자 오버로딩
    if(a.second == b.second) return a.first > b.first; // pair의 두 번째 값이 같으면 첫번째 값 비교
    return a.second > b.second; // 두 번째 값을 기본적으로 비교한다.(오름차순)
  }
}
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq; 
```

## Bonus : Binomial Heap
