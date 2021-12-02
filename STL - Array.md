# STL, Array
---
## Define Array
```C++
#include <iostream>
#include <array>
#include <algorithm>

#define pout(MSG, x) cout << "\n" << MSG << X << "\n"; // 이렇게 #define으로 함수를 매크로로 만들어 놓으면 매우 유용하다!

array <double, 5> my {9.0, 7.2, 5.4, 3.6, 1.8}; // double my[5] = {}(C-Style) 와 같다.
cout << "제일 첫 원소" << my.front() << endl;
cout << "제일 마지막 원소" << my.back() << endl;
```
- Array와 Vector의 차이는?
  - Array는 크기가 고정된다. 하지만 Vector은 뒤가 트여 할당 및 해제가 자유롭다.

### For loop with Array
```C++
array <int, 5> arr = {11, 22, 33, 44, 55};
for(auto iter = arr.begin(); iter != arr.end(); ++iter){ // 이렇게 arr.begin()과 arr.end()를 이용해 for문을 돌려 Iterate한다.
    cout << *iter << endl;
}

for(auto U : arr){ // Range-Based For loop (Foreach loop)
  cout << U << " ";
}
```
- Array의 method에는 ```arr.begin()```, ```arr.back()```, ```arr.end()```가 있다.
- 이들은 모두 값이 아닌 주소를 반환한다.
- ```arr.back()```과 ```arr.end()```를 잘 구분해야 하는데, ```arr.end()```는 제일 마지막 원소가 아닌 그 다음 쓰레기 값을 가리키게 된다.
  - ```arr.end()```가 그럼 왜 필요한가? 배열이 끝났음을 알리기 위해서 존재한다.

### Size of Array
```C++
bool barray[] = {true, false, false};
int iarray[] = {1,2,3,4,5,6};
long long llarray[] = {1,2,3};
long double ldarray[] = {0.1,0.2,0.3};

cout << xsize(barray) << endl; // 3
cout << xsize(iarray) << endl; // 4 * 6 = 24
cout << xsize(llarray) << endl; // 8 * 3 = 24
cout << xsize(ldarray) << endl; // 16 * 3 = 48
cout << size(iarray) << endl; // 6
```
- 위의 예시에서 알 수 있는 점은, ```xsize()```와 ```size()```의 차이점이다.
- ```xsize()```는 Array 내의 Value들의 크기를 측정해서 size를 알려주지만
- ```size()```는 배열의 길이를 반환해준다.

```C++
int A[20000][20000]; // ```main()``` 외부에 선언 시 생성이 되며, For loop을 통한 출력 또한 가능하다. 

int main(){
  int B[20000][20000]; // 생성이 불가능하다. Local variable 일 땐, 약 700칸 정도까지 밖에 안 만들어진다.
}
```

## 2D Array
```C++
array<array<int, 6>, 5> arr{{{11,12,13}, {21,22,23}, {33,34,35}}}; // 채워지지 않은 곳은 자동으로 0으로 채워진다.
                                                                   // C-Style과 차이는 {} 중괄호가 하나 더 들어가있다는 점이다.
array<array<int, 3>, 2> arr2{ array<int, 3>{51,42,33}, array<int, 3>{41, 52, 63}}; // 2D Array 또한 크기를 Compile time에 확정하여야 된다.
```

## Dynamic Array
- C++ 11 version 부터 없어졌다. ==> 우리는 Vector을 이용한다!

## Array method
```C++
array<int, 12> arr;
array<int, 12> arr2;
arr.fill(100); // arr을 모두 100으로 채운다.
sort(arr.begin(), arr.end()); // Generic Sort 함수이다.
reverse(arr.begin(), arr.end()); // 위와 같은 종류, 배열을 뒤집는다.
arr2 = arr; // C++의 STL 에서는 단순히 ```=``` Operator 만으로 배열 복사가 가능하다.
```

## Custom Sort Function
```C++
#define CT 1
bool custom(array<int, 5> i, array<int, 5>j){
  return (i[CT] < j[CT]);
}

int main(){
  array<int, 5> a = {10, 20, 31, 40, 50};
  array<int, 5> b = {10, 20, 30, 40, 51};
  array<int, 5> c = {50, 40, 30, 20, 10};
  array<int, 5> d = {5, 20, 30, 40, 50};
  array<int, 5> e = {50, 4, 30, 0, 10};
  
  array<array<int, 5>, 6> Urray;
  Urray[0] = a; Urray[1] = b; Urray[2] = c; Urray[3] = d; Urray[4] = e;
  
  sort(Urray.begin(), Urray.end(), custom)
}
```
- 위와 같이 ```sort()``` 함수의 Sorting 기준을 내 마음대로 bool 함수를 통해 Custom 할 수가 있다.
- 위의 경우에는 ```i[1] < j[1]``` 이라는 조건을 통해서 5개의 array를 1번째 원소 크기를 기준으로 오름차순 정렬을 했음을 알 수 있다.
- 물론 ```i[1] > j[1]``` 로 바뀔 경우, 내림차순으로 정렬된다.

## Bonus : Container별 속도 비교
- Generic Sort Algorithm
  - Vector에서의 Generic Sort는 __O(NlogN)__ 의 복잡도를 가지는데, Rough 하게 거의 __O(N)__ 이라고 봐도 무방하다.
- Insertion
  - ```Vector.begin()``` >>>>>> ```list.begin()``` == ```list.back()``` > ```vector.back()```
  - 벡터는 기본적으로 ```push_back()``` 을 사용하므로, 제일 앞에 집어 넣는 것은 시간이 많이 소요된다.
- Reversing
  - Array > Vector > Deque > List
