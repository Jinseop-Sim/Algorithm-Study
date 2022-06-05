# STL, Set!
---
> Set은 중복을 허용하지 않는 Container이다.  
> Map과 같은 Associatvie Container이다.  

## Define set
```C++
set<int> s; 
set<int> s(cmp); // cmp에 따라 정렬한다.
set<int> new_s(old_set); // old_set을 new_s로 복사한다.
```
- Set은 위와 같이 정의한다.
  - Balanced Binary Tree 구조로 이루어져 있다.
  - 따라서 기본적으로 정렬이 되어 삽입이 된다.

## Set methods
```C++
set.count(k); // K라는 원소의 갯수를 반환한다. 중복을 허용하지 않는 set은 무조건 0 or 1이다.
set.insert(k); // K라는 원소를 삽입한다. 자동으로 정렬된 위치에 삽입된다.
set.erase(iter); // Iter이 가리키는 원소를 지운다.
set.find(k); // K라는 원소의 Index를 가리키는 Iterator을 반환한다.
set.size(); // Set의 Size, 원소의 수를 반환한다.
```
