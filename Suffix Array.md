# Suffix Array
---
> 문자열 S가 주어졌을 때, 모든 접미사(Suffix)를 사전순으로 저장해놓는 배열을 Suffix Array라고 한다.  
> 이 자료구조는 특정 문자열의 검색에 유용하게 사용된다.  

## How?
- 가장 단순한 방법은 Suffix를 모두 만든 후, 직접 정렬하는 것이다. (이는 O(N^2 log^2)이 소모된다. 낭비!)
  - 가장 빠른 방법은 O(N)만에 만들 수가 있다! (하지만 복잡하다.)
  - 가장 쉬운 방법은 O(NlogN)만에 만들어진다. - Manber-Myers

## Manber-Myers Algorithm
> Suffix Array를 정렬하는 대표적인 방법이다.  

![image](https://user-images.githubusercontent.com/71700079/173976407-9302e336-7fbb-4ceb-97e2-76ce51606bd9.png)   
- 첫 단계에서는 먼저 제일 앞 1글자를 기준으로 Rank를 매겨 대강 정렬을 한다.  
![image](https://user-images.githubusercontent.com/71700079/173976593-b9ae9598-b783-45a7-8220-c1b9d948188a.png)  
![image](https://user-images.githubusercontent.com/71700079/173976728-20ea9c8e-8c49-4422-9222-d35337302137.png)  
- 두 번째 단계에서는, 2글자 씩 검사를 한다.
  - 이 때 Rank는 Pair로 매기게 되는데, 그 이유는 앞에서 이미 정렬된 정보를 그대로 사용하기 위함이다.
  - ex) AB의 Rank가 (1, 2)인 이유는 A가 Rank 1이었고, B가 Rank 2였기 때문이다.  
![image](https://user-images.githubusercontent.com/71700079/173976754-05084523-19ea-47e8-b78f-fa31082c84ba.png)  
- 세 번째 단계에서는 4글자 씩 검사를 한다.
  - 이후 단계들은 지금처럼 (이전 단계 글자 수 X 2) 글자의 탐색을 하게 된다.
    - Why? 이전 정렬 결과를 Pair로 사용하기 때문!
  - ex) ABAA가 Rank가 (2, 1)인 이유는 앞서 2글자 정렬에서 AB의 Rank가 2, AA의 Rank가 1이었기 때문이다.

## LCP Algorithm(Kasai's)


### Reference
- http://www.secmem.org/blog/2021/07/18/suffix-array-and-lcp/
