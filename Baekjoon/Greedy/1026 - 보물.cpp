#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int num = 0, temp = 0, sum = 0;
priority_queue<int> A;
priority_queue<int, vector<int>, greater<int>> B;

int main(void) {
	cin >> num;
	for(int i = 0; i<num; i++){
		cin >> temp;
		A.push(temp);
	}
	for (int i = 0; i < num; i++) {
		cin >> temp;
		B.push(temp);
	}

	while (!A.empty()) {
		sum += A.top() * B.top();
		A.pop(); B.pop();
	}
	
	cout << sum;
}

// 간단한 Greedy 문제였다.
// Greedy 문제는 대개 수학적인 면을 많이 요구하는 것 같다.
// 수를 최소로 만드려면 배열 하나는 오름차순, 하나는 내림차순으로 만들어서 둘을 계산해야 한다.
