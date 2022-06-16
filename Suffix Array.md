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

```C++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 10

string word;
int word_size = 0, group_k = 0, suffix_arr[MAX_N], group[MAX_N], next_group[MAX_N];
bool cmp(int x, int y) {
	if (group[x] == group[y]) return group[x + group_k] < group[y + group_k];
	return group[x] < group[y]; // Group의 글자들만 보고 정렬한다.
}

void make_sa(string& s) {
	group_k = 1;
	word_size = s.size();

	for (int i = 0; i < word_size; i++) {
		suffix_arr[i] = i;
		group[i] = s[i]; // 첫 글자를 기준으로 Group을 결정
						 // 각 자리의 글자는 모든 접미사의 첫 글자가 된다.
	}

	while (group_k <= word_size) { // Group size가 Word_size보다 커지면 종료. ( 1, 2, 4, 8...)
		group[word_size] = -1;
		sort(suffix_arr, suffix_arr + word_size, cmp); // Group의 글자들을 기준으로 정렬

		next_group[suffix_arr[0]] = 0; // Group의 할당을 위해, 첫번째 번호 배정
		for (int i = 1; i < word_size; i++) {
			if (cmp(suffix_arr[i - 1], suffix_arr[i]))
				next_group[suffix_arr[i]] = next_group[suffix_arr[i - 1]] + 1; // Group이 다르면 (다른 글자) 다음 Group
			else
				next_group[suffix_arr[i]] = next_group[suffix_arr[i - 1]]; // Group이 같으면 (같은 글자) 번호 그대로
		}
		for (int i = 0; i < word_size; i++)
			group[i] = next_group[i]; // 새로운 Group으로 Group 할당
		group_k <<= 1; // Group Size * 2
	}
}

int main(void) {
	cin >> word;
	make_sa(word);
	for (int i = 0; i < word_size; i++) cout << suffix_arr[i] << " ";
	return 0;
}
```

## LCP Algorithm(Kasai's)


### Reference
- http://www.secmem.org/blog/2021/07/18/suffix-array-and-lcp/
