#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void air_input(int n, vector<deque<int>> &airline, deque<int> temp){
    for(int i = 0; i < n; i++){
        int num;
        temp.clear();
        do{
            cin >> num;
            temp.push_back(num);
        } while(num != 0);
        airline.push_back(temp);
    }
}

void calc_airline(int n, vector<deque<int>> &airline) {
    while (1) {
        int min = 10001, min_idx = 0;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (airline[i][0] != 0 && min > airline[i][0]) {
                min = airline[i][0];
                min_idx = i;
            }
            if(airline[i][0] != 0) flag = false;
        }
        if(flag) break;

        cout << airline[min_idx][0] << endl;
        airline[min_idx].pop_front();
    }
}

int main(void){
    vector<deque<int>> airline;
    deque<int> temp;

    int n;
    cin >> n;
    air_input(n, airline, temp);
    calc_airline(n, airline);
    return 0;
}