#include <iostream>
#include <set>
using namespace std;

struct cmp {
	bool operator()(const string& a, const string& b) const{ // Set도 PQ와 마찬가지로 정렬이 가능하다.
		if (a.length() == b.length()) return a < b;
		return a.length() < b.length();
	}
};

int num = 0;
string word;
set<string, cmp> words;

int main(void) {
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> word;
		words.insert(word);
	}
	for (auto i : words) cout << i << endl;
}
