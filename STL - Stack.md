# STL, Stack
---
## Stack ?
> 스택은 탑을 쌓는다고 생각하면 된다.  
> Bottom 부터 쌓이고, Top부터 나간다.  
> Stack이 좋은 이유는, 옆구리에서 값을 빼갈 수 없다는 점이다. 오직 앞에서 쌓기만 할 수 있는 자료구조이다.  
> 따라서 자료를 전달할 때에 남이 임의로 값을 빼거나 넣지 못해서 유리하다.  

## Stack Number
> Stack Number이란, Pass과정과 Push, Pop을 이용해서 만들 수 있는 수의 나열을 말한다.  
- 예를 들어, 1 2 3 이라는 숫자를 생각해보면
- 1 2 3 은 당연히 가능하고, 2 1 3도 1 push 2 pass 1 pop 3 push pop 을 하면 가능하다.
- 이 때, 3 1 2는 같은 방식으로 해보면 불가능 함을 알 수있다.
- Stack Number의 규칙은 순서대로 들어왔을 때 Stack Number은 반드시 숫자 크기의 역순이 되어야함을 알 수 있다.
  - Example) 7 6 5 1 2 3 4 (X) 4 3 2 1 7 6 5 (O)
- K Stack Number(Stack의 갯수가 증가)가 문제로 출제될 수 있다.

## Define Stack
```C++
#include <iostream>
#include <stack>
stack <type> name;
name.push(value); // value를 stack 안의 Bottom에 집어 넣는다.)
name.emplace("John"); // 값을 변수에 넣지 않고 그냥 Raw하게 집어넣으려면 Emplace를 이용해야 한다.
name.pop(); // 값을 지우며 return한다. 빈 Stack에서 ```pop()```을 하면 당연히 Runtime error가 발생한다.
name.top(); // 값을 그냥 copy만 해오는 것. 빈 Stack에서 ```top()```을 하면 당연히 Runtime error가 발생한다.

void safe_pop(stack<type> &s){
  if(!s.empty()) s.pop();
  else throw underflow_error("It's Empty! Danger!"); // 이와 같이 함수를 따로 만들어줘서 빈 Stack에 동작을 수행하는 걸 막을 수 있다.
}
```

## Copy Stack
```C++
stack <string> cards;
stack <string> another;
another = cards;
```
- Stack은 위와 같이 Copy가 가능하다.

## Print Stack ?
```C++
template <typename T>
ostream & operator << (ostream & os, stack<T> my_stack){
  cout << "\n Stack : ";
  while(!my_stack.empty()){
    os << my_stack.top() << " ";
    my_stack.pop();
  }
  return os;
}
vector<int> myin {34, 10, 19, 88, 70, 11, 5, 50};
stack<int> mys;

for(auto& s: myin){
  mys.push(s);
  cout << " " << (&s - &myin[0]); // 원소 출력 순서 계산. Stack 이니까 거꾸로 나와야한다.
}
cout << "\n mys stack : " << mys; // 50 5 11 70 8 19 10 34
```
- 위와 같이 __Operator Overloading__ 을 통해서 ```<<``` 연산자로 출력되지 않는 Container을 가능하게 만든다.

## Stack Variation
### Vector in Stack
```C++
typedef vector<string> Intvec;
void print_SVEC(stack <Intvec> S){ // 벡터 출력 함수
  int i = 0;
  while(!S.empty()){
    cout << "\n" << to_string(i++) << " : ";
    for(auto w : S.top()) cout << w << ", ";
    S.pop();
  }
}

int main(){
  Intvec meal;
  stack <Intvec> SVEC; // Vector in Stack.
  meal.push_back("pizza");
  meal.push_back("coke");
  meal.push_back("pickle);
  SVEC.push(meal); meal.clear(); // Meal 이라는 Vector에 원하는 정보를 넣은 다음 Stack에 삽입.
                                 // 새 정보 입력을 위해 반드시 비워줄 것.
}
```

## 다변수 일차방정식의 해 구하기
