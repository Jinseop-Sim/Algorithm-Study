# Vector
---
## Tuple in vector
```
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int main(){
  vector <i3tuple> v;
  
  for(int i=0; i<10; i++){
    v.push_back(i3tuple(i, i*2, i*i*1) ); // How to Initialize Tuple.
  }
  
  for(i3tuple t : v){
    cout << get<0>(t) << ' ';
    cout << get<1>(t) << ' ';
    cout << get<2>(t) << '\n';
  }
}
```
- 위와 같이 벡터 내에다 Tuple을 저장할 수 있다.
- Tuple은 <tuple> 헤더를 써야하며, i3tuple(i, i*2, i*i*1) 과 같이 초기화를 시킨다.
- 그리고 벡터 내의 Tuple을 출력하고 싶으면, get<n>(tuple) 과 같은 함수를 이용한다.
