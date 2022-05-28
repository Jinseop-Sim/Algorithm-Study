# Radix Sort
---
> Radix Sort(기수 정렬)에 대해서 간단하게 알아보자.  

- 흔히 __Sorting Algorithm__ 이라고 하면 떠오르는 정렬들이 있다.
  - __O(N^2)__
    - 선택 정렬(Selection Sort) : 앞에서 부터 하나씩 선택해서 정렬
    - 버블 정렬(Bubble Sort) : 제일 흔한 정렬, 매번 연속된 두 값을 비교하며 정렬
    - 삽입 정렬(Insertion Sort) : 두 번째 부터 하나씩 선택해서 뒤로 탐색하며 정렬
  - __O(NlogN)__
    - 병합 정렬(Merge Sort) : Divide & Conquer을 이용한 정렬로, 하나하나 다 쪼갠 뒤 비교하며 병합
    - 퀵 정렬(Quick Sort) : Pivot 값을 하나 잡고 작은 값은 왼쪽 큰 값은 오른쪽으로 모두 옮겨(분할) 반복하여 정렬한다.
    - 힙 정렬(Heap sort) : 힙에 값을 모두 집어넣어서 Root에 오는 값을 최대 혹은 최소 값으로 만든다.
- 위 정렬 방식들의 특징은 뭘까?
  - 바로 __값을 비교한다__ 는 점이다.
  - 하지만 Radix Sort는 실제 값을 비교하지는 않는다.

## LSD Radix Sort
> Radix Sort 중 LSD(Least Significant Digit) 방식의 기수 정렬이다.  
- 이 방식은 숫자로 치면 뒷자리부터 확인하며 정렬하는 방식이다.
- 기본적으로 Radix Sort를 이용하려면 Queue가 하나 필요하다.  
![image](https://user-images.githubusercontent.com/71700079/170820647-98e3c8e3-a26b-4d74-bf91-ce7444470ab2.png)  
  - 위와 같이 각 자리에 맞는 값의 Queue로 집어넣은 다음,
  - 앞에서부터 Pop하면서 배열에 차례대로 넣으면 해당 자리가 정렬이 된다.
  - 이렇게 제일 앞자리까지 정렬을 하면 된다.
  - 시간 복잡도는 __O(N)__ 으로 귀결된다.


## MSD Radix Sort
> Raidx Sort 중 MSD(Most Significant Digit) 방식의 기수 정렬이다.  
- 이 방식은 앞자리부터 확인하며 정렬하는 방식이다.
  - 이 방식의 장점은 가변 길이의 String 또한 정렬이 가능하다는 점이다.  
![image](https://user-images.githubusercontent.com/71700079/170820824-b227f554-7fe6-4218-b81e-31391e4ee6b5.png)  
  - Queue에 넣는 방식은 동일하나, 이 방식은 재귀로 진행해야한다.
  - 왜냐하면, 재귀로 진행하지 않을 경우 매 자리를 정렬할 때마다 정렬이 다 흐트러지기 때문이다.
  - 시간 복잡도는 마찬가지로 __O(N)__ 으로 귀결된다.

### Radix sort : Counting sort
> Radix sort에서 Queue에 넣는 동작은 시간 비용이 생각보다 많이 든다.  
> 따라서 __Counting Sort(계수 비교)__ 를 이용해서 시간을 조금 줄여보자.  

![image](https://user-images.githubusercontent.com/71700079/170820995-a712f494-bfed-4b71-9fa1-b8a4b6aea48b.png)  
- 위와 같이 Queue가 아닌 Count 배열을 미리 만들어 놓고 진행한다.
  - Queue에 Push하고 Pop하는 것보다 이미 선언된 배열의 값을 고치는게 훨씬 값이 싸다!
  - 이를 Radix Sort와 결합하면, 최고의 성능을 낼 수 있다.
  - 그 시간 복잡도는 __O(N)__ 이 된다.

