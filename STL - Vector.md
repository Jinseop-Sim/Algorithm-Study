# Vector
---
## Define vector
```c++
#include <vector>
#include <iostream>
using namespace std;

int main(){
  vector <int> myv {11, 22, 33, 44, 55, 66};
  
  myv.push_back(999);
  for(auto s : myv) cout << s << ", ";
  myv.pop_back();
  myv.pop_back();
  for(auto s : myv) cout << s << ", ";
  
  return 0;
}
```

- Vector은 위와 같이 vector <type> name; 으로 정의한다.
- 위와 같은 형태로 초기화 또한 가능하다.
- push_back() 메서드로 제일 뒤에 원소를 삽입하며, pop_back() 메서드로 제일 뒤의 원소를 추출한다.
- for(type name : arrayname)의 형태는 Range-Based Loop로, 이 형태를 주로 이용하는게 좋다.  

## Size of Vector
