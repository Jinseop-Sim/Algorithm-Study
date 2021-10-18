# STL, Linked list
---
## Linked List?
> 논리적인 연속 자료 구조를 구현할 수 있는 가장 기초적인 자료구조이며, 현장에서 매우 많이 활용 된다.  
> 동적 할당과 포인터를 기반으로 구현되기 때문에, 메모리의 크기에 유연하게 대처가 가능하다.  
> 또한 pop_front()와 push_front()가 존재해서 Deque와 유사한 동작이 가능하며, 반복자를 이용하여 원소에 접근 및 할당을 한다.

## Define List
```C++
#define allout(MSG, X) cout<<"\n"<<MSG<<" "; for(auto w:X) cout << w << ", "

int main(void) {
	list<int> myL;
	for (int i = 0; i < 5; ++i) myL.push_front(i);
	allout("1. myList = ", myL); // 4 3 2 1 0, 앞에서 부터 넣었으므로 역순.

	for (int i = 0; i < 5; ++i) myL.push_back(-i);
	allout("2. myList = ", myL); // 4 3 2 1 0 0 -1 -2 -3 -4

	myL.pop_front();
	allout("3. myList = ", myL); // 3 2 1 0 0 -1 -2 -3 -4, 제일 앞에 걸 pop.
}
```
- 위와 같이 정의하고 ```pop()```, ```push()```를 하며, Vector나 Deque와 같이 for loop을 통한 출력이 가능하다.

## Iterator in list
```C++
list<string> list1 = { "다람쥐", "너구리", "오소리", "도마뱀", "물개" };
list<string>::iterator it; // 이렇게 Iterator을 선언하여 list의 주소를 반환시킬 수 있다.

cout << "size() = " << list1.size(); // 5, 원소의 갯수를 출력한다.

it = list1.begin(); // 시작주소를 iterator에 저장한다.
int count = 1;
while (it != list1.end()) {
  cout << "\n" << count++ << " = " << *it; // 다람쥐 ~ 물개까지 순서대로 출력 된다.
	it++; // it = it+1로 써서는 안된다, 이는 덧셈의 개념이 아닌 일종의 Jump이기 때문!
	}
```

### What is end()?
> ```list.end()``` 에는 List의 마지막 주소가 아닌, List의 마지막의 다음 주소. 즉 쓰레기 공간의 주소가 저장되어 있다.  
> 왜 그렇게 저장을 하는 것일까? 그것은 바로 마지막 값까지 참조를 할 수 있도록 하기 위함이다.  
