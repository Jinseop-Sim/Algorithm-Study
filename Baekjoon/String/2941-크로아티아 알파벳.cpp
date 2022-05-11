#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> cro_alpha = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
string str;
int idx;
int main() {
	cin >> str;
	for (int i = 0; i < cro_alpha.size(); i++) {
		while (true) {
			idx = str.find(cro_alpha[i]); // 여기서 해당 단어가 있다면 시작 idx를 반환하고, 없다면 npos를 반환한다.
			if (idx == string::npos) break; // string header의 find 함수가 단어를 찾지 못한 경우에 반환되는 값이 npos이다.
			str.replace(idx, cro_alpha[i].length(), "#"); // 해당 단어의 시작 idx부터 그 단어의 길이 만큼을 통째로 #으로 변환한다.
		}
	}
	cout << str.length(); // #의 갯수만 세주면 된다!
	return 0;
}

// string::npos라는 생소한 Keyword를 이용해보았다.
