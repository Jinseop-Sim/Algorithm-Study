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

## Resize()
```c++
#include <iostream>
#include <vector>
  
int main(){
  vector <int> vex = {11, 22, 33, 44, 55, 66};
  for(auto s : vex) cout << " " << s;
  vex.resize(3); // 11 22 33
  for(auto s : vex) cout << " " << s;
  vex.resize(5); // 11 22 33 0 0
}
```
- Vector은 resize() 메서드를 이용해서 크기를 조정할 수 있다.
- resize() 메서드로 크기를 줄이게 되면, 원래 있던 원소들은 크기를 줄이며 삭제되어, 다시 늘릴경우 0으로 채워진다.

## Copy Vector
```c++
#include <iostream>
#include <vector>
 
int main(){
  vector <int> v1, v2, v3;
  v1.push_back(71) ;
  v1.push_back(81) ;
  v1.push_back(91) ;
  v1.push_back(45) ;
  
  for(auto s : v1) cout << s << " "; // 71 81 91 45
  
  v2 = v1;
  v2.push_back(999);
  for(auto s : v2) cout << s << " "; // 71 81 91 45 999
  for(auto s : v1) cout << s << " "; // 71 81 91 45
}
```
- Vector를 Copy하는 방법에는 대표적으로 세 가지가 있다.
  - Equal operation : 그냥 = 으로 복사를 할 수 있다. 그럼 rvalue가 lvalue로 통째로 복사가 된다.
  - Copy(), Copy_n() : copy(v1.begin(), v1.begin()+3, v2.begin()) 과 같이 메서드를 사용하면, v1의 시작점부터 3칸 만큼 v2에 복사를 하는 것이다.
                       copy_n(v1.begin(), 4, v2.begin()) 과 같이 메서드를 사용하면, copy()와는 다르게 칸 수를 숫자로 지정하여 복사를 하는 것이다.
  - Assign() :
  
## 2 Dimensional Vector
```c++
#include <iostream>
#include <vector>
#include <stdio.h>
  
using namespace std;

int main(){
  vector<vector <int>> vv { {99, 100}, {-12}, {72,77,76}, {3,2,1,0}};
  
  int i, j ;
  i = j = 0;
  for(auto vec : vv){
    for(auto w : vec){
      printf(" vv[%d][%d] = %d \n", i, j, w); // vv[0][0] = 99, vv[0][1] = 100 .. vv[3][3] = 0
      ++j
    }
    j = 0 ; ++i ;
  }
}
```
- 위와 같이 벡터도 배열처럼 2차원 벡터를 만들 수 있다. vector<vector <int>> name; 벡터안에 벡터를 집어넣는 것이다.
- 여기서 또 주목할 점은 for문의 Range-Based loop도 이중 루프로 쓸 수 있다는 점이다.
