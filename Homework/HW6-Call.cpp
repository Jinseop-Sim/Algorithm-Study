#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void input_func(int n, vector<vector<string>> &function){
    string seq;
    for (int i = 0; i < n; i++){
        vector<string> temp;
        do{
            cin >> seq;
            if (seq != "$")
                temp.push_back(seq);
        }while(seq != "$");
        function.push_back(temp);
    }
}

void call_func(int n, vector<vector<string>> &function, int idx, vector<string> &result, int count){
    for (int i = 1; i < function[idx].size(); i++){
        bool flag = true;
        for (int j = 0; j < n; j++){
            if(function[idx][i] == function[j][0]) {
                count++;
                if(count > 200){
                    cout << "DEADLOCK";
                    exit(0);
                }
                call_func(n, function, j, result, count);
            }
        }
        for (int j = 0; j < n; j++){
            if(function[idx][i] == function[j][0]) flag = false;
        }
        if(flag == true) {
            string exec = function[idx][0] + "-" + function[idx][i];
            result.push_back(exec);
        }
    }
}

void print_answer(int k, vector<string> result){
    if(k > result.size()) cout << "NONE" << endl;
    else cout << result[k - 1] << endl;
}

int main(){
    int n, k1, k2, count = 0;
    vector<vector<string>> function;
    vector<string> result;
    cin >> n >> k1 >> k2 ;
    input_func(n, function);
    call_func(n, function, 0, result, 0);
    print_answer(k1, result);
    print_answer(k2, result);
}
