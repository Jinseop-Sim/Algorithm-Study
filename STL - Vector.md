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
```c++
#include <vector>
#include <iostream>
using namespace std;

int main(){
  vector <int> va;
  vector <int> vb {11, 22, 33, 44, 55, 66};
  
  cout << "   sizeof(va) = " << sizeof(va); // 12
  cout << "\n va.size() = " << va.size(); // 0
  cout << "\n sizeof(vb) = " << sizeof(vb); // 12
  cout << "\n vb.size() = " << vb.size(); // 6
```
- Vector의 크기를 확인할 수 있는 2가지 메서드이다.
- sizeof(v) 메서드는 선언된 객체의 크기를 반환해주는 함수로, Vector은 Pointer 3개로 구성된 객체라서, 4 * 3 = 12가 반환되었다.
- v.size() 메서드는, 선언된 Vector 내의 원소 갯수를 반환해주는 함수로, va는 0 vb는 6이 반환된다.
