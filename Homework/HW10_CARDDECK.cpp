#include <iostream>
#include <list>
using namespace std;
#define allout(x) for(auto i : x) cout << i << " "; cout << endl;

void make_deck(int n, list<int>& deck) {
    for (int i = 0; i < n; i++) deck.push_back(i + 1);
}

void shuffle(int n, list<int>& deck) {
    list<int> temp;
    list<int>::iterator it_deck = deck.begin();
    list<int>::iterator it_temp = deck.begin();
    for (int i = 0; i < n / 2; i++) it_temp++;
    temp.splice(temp.begin(), deck, it_deck, it_temp);
    it_deck = deck.begin();
    for (int i = 0; i < n / 2; i++) {
        it_temp = temp.begin();
        deck.splice(it_deck, temp, it_temp);
        it_deck++;
    }
}

void cut(int n, list<int>& deck, int start, int end) {
    list<int>::iterator it_start = deck.begin();
    list<int>::iterator it_end = deck.begin();
    for (int i = 0; i < start - 1; i++) it_start++;
    for (int i = 0; i < end; i++) it_end++;
    deck.splice(deck.end(), deck, it_start, it_end);
}

void input_act(int n, int k, list<int>& deck) {
    string act;
    int c_start = 0, c_end = 0;
    for (int i = 0; i < k; i++) {
        cin >> act;
        if (act == "Shuffle") {
            shuffle(n, deck);
        }
        if (act == "Cut") {
            cin >> c_start >> c_end;
            cut(n, deck, c_start, c_end);
        }
    }
}

int main(void) {
    list <int> deck;
    int n = 0, k = 0;
    cin >> n >> k;
    make_deck(n, deck);
    input_act(n, k, deck);
    list<int>::iterator it = deck.begin();
    for (int i = 0; i < (n / 2) - 1; i++) it++;
    cout << deck.front() << " " << *it << " " << deck.back();
}
