#include <iostream>
using namespace std;
#define MAX_BIT  0b111111111111111111111
#define MASK_BIT 1 << value

int M, value = 0, bit = 0;
string oper;

void preset() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int convert_oper(string oper) {
	string oper_set[6] = { "add", "remove", "check", "toggle", "all", "empty" };
	for (int i = 0; i < 6; i++) {
		if (oper == oper_set[i]) return i;
	}
}

int main(void) {
	preset();

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> oper;
		switch (convert_oper(oper))
		{
		case 0:
			cin >> value;
			bit |= MASK_BIT; // 내가 원하는 자리까지 Shift 후 1로 만들어준다. ( 1 << value)
			break;
		case 1:
			cin >> value;
			bit &= ~(MASK_BIT); // 내가 원하는 자리만 0으로 만들고 나머지는 다 1로 만드는 MASK. 
			break;
		case 2:
			cin >> value;
			if (bit & MASK_BIT) cout << 1 << '\n'; // 내가 원하는 자리와 &를 해서 1이 나온다는 것은 그 자리가 1이라는 것.
			else cout << 0 << '\n'; // 아니면 0이라는 것.
			break;
		case 3:
			cin >> value;
			bit ^= MASK_BIT; // 1과 계속 XOR을 할 경우, 해당 자리 Toggle 동작이 가능하다.
			break;
		case 4:
			bit = MAX_BIT; // 1 ~ 20까지를 모두 1로.
			break;
		case 5:
			bit = 0; // 0으로 초기화
			break;
		}
	}

	return 0;
}

// 처음엔 배열을 이용해서 풀었지만, 시간초과가 계속 발생했다.
// Bit masking을 이용해서 풀어본 문제는 처음이었다.
