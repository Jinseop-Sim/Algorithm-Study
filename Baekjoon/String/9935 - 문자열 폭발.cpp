#include <iostream>
#include <string>
using namespace std;

string word, C4;
string ans = "";
void find_C4(int C4size) {
	for (int i = 0; i < word.size(); i++) {
		ans.push_back(word[i]); // 하나씩 결과 String에 Push back한다.
		if (ans.back() == C4.back()) { // Push_back하다가 마지막 글자가 C4와 같다면?
			bool check = true;  // 일단 C4가 있음을 의심하고 Check를 true로 바꾼다.
			for (int j = 1; j <= C4size; j++) { 
				if (ans[ans.size() - j] != C4[C4.size() - j]) // ans의 마지막부터 하나씩 뒤로가면서, C4도 마지막부터 하나씩 뒤로가면서 동시에 검사한다.
					check = false; // 만약 다른 문자가 발견되면, C4는 없는 것!
			}
			if (check) {
				for (int j = 0; j < C4size; j++) ans.pop_back(); // 다른 문자가 발견되지 않았다면, C4의 크기만큼 Pop_back() 해버린다.
			}
		}
	}
}

int main(void) {
	cin >> word >> C4;

	string ans = "";

	find_C4(C4.size());

	if (ans.empty()) cout << "FRULA";
	else cout << ans;
	
	return 0;
}

// Vector을 Stack처럼 이용한다.
