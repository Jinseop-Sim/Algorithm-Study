# Queue
---
## Queue?
> Stack은 Push와 Pop이 하나의 구멍에서만 일어나는 반면, Queue는 양쪽 구멍을 모두 쓰는 자료구조이다.  
> Push를 앞에서부터 하고, Pop 또한 제일 앞에서 부터 실행된다. 놀이공원 줄서기를 생각하면 간단하다.  
> Queue는 __Container__ 이 아닌 __Container Adapter__ 이다. 즉 반복자를 지원하지 않는다. 이 점을 유의하자.  

### What is Container Adaptor?
> 기존 Container와 형태는 동일하지만, 기능이 제한되거나 조금 변형된 Container을 말한다.  
> 정해진 특정 동작만을 수행하도록 설계되어있다.  
> Container Adapter에는, __Queue, Stack, Priority Queue(우선순위 큐)__ 가 존재한다.  

## Queue & Deque
```C++
#include <queue>
#include <deque>
#include <stack>
#include <vector>

int main(void){
   vector<int> v {11, 12, 13, 14, 15};
   queue<int> myQ; // Queue와 Stack은 Vector 처럼 초기화 시킬 수 없다.
   stack<int> myS; // 둘은 Container이 아닌 Container Adapter이기 때문이다.
   deque<int> myD {11, 12, 13, 14}; // Deque는 Container이다. 즉 반복자로 접근이 가능하고 초기화도 가능하다.
   
   myQ.push(31);
   myQ.push(21);
   myS.push(31);
   myD.push_front(30); // Deque는 쌍방향 Queue이므로, push_front(), push_back() 두 가지가 모두 가능하다. 물론 pop 또한 마찬가지이다.
   
   cout << myQ.front() << " " << myQ.back() << endl;
   cout << myS.top() << endl;
   for(auto e : myD) cout << e << endl; // Deque는 Container 이므로, Vector와 같이 Range-Based for loop을 이용한 출력 또한 가능하다.
}


```
