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
  
  for(auto &w : myv) { cout << ++w << " , " ; } // 이렇게 Reference를 이용해 참조하면 Vector Element의 값이 아예 바뀌어 버린다.
  for(auto r : myv) { cout << r << " , " ; }
  return 0;
}
```
- Vector은 위와 같이 vector <type> name; 으로 정의한다.
- 위와 같은 형태로 초기화 또한 가능하다.
- push_back() 메서드로 제일 뒤에 원소를 삽입하며, pop_back() 메서드로 제일 뒤의 원소를 추출한다.
- for(type name : arrayname)의 형태는 Range-Based Loop로, 이 형태를 주로 이용하는게 좋다.  
- 여기서 Auto 라는 Type은 자동으로 적절한 type으로 맞춰주는 매우 유용한 type이다.
  
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

## Begin(), End()
```c++
include <iostream>
include <vector>
using namespace std;

int main(){
  vector <int> intvec { 34, 23, 99, -100, 1, 3, 55 };
  
  cout << "\n Practice 01 begin()   = "     << *intvec.begin() ; // 34
  cout << "\n Practice 02 *(begin()+2) = "  << *(intvec.begin()+2) ; // 99
  cout << "\n Practice 03 *begin()+2  =  "  << *intvec.begin()+2 ; // 36
  cout << "\n Practice 04 end()-1 = "       << *(intvec.end()-1) ; // 마지막 원소는 end()-1
  cout << "\n Practice 05 end()-2 = "       << *(intvec.end()-2) ;
  cout << "\n Practice 06 end() Value  = "  << *intvec.end() ; // 0
}
```
- Vector은 begin()과 end() 메서드를 이용해서 시작 값과 끝 값에 접근할 수 있다. 물론, 반환이 아닌 포인터처럼 가리키기만 하는 것!
  - 반환을 하기 위해서는 front()와 back() 메서드를 통해서 진행한다.
- 위의 예시를 보면, *(intvec.begin() + 2)는 99이지만, *intvec.begin()+2는 36임을 알 수 있다. 이는 포인터와 유사하게 동작한다는 의미!
