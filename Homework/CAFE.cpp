#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void where_sit(int spot[], vector<int> &check){
    int dist = 0;
    spot[0] = 0, spot[1] = 0;
    sort(check.begin(), check.end());
    if(check.size() == 0) spot[0] = 0, spot[1] = 0;
    else{
        for(int i=1; i<check.size(); i++){
            if(dist < check[i] - check[i-1]){
                dist = check[i] - check[i-1];
                spot[1] = dist;
                spot[0] = check[i-1];
            }
        }
    }
}

void how_to_sit(int n, int k, int info[], vector<int> &check){
    int spot[2] = {};
    int customer = 0;
    bool flag = true;
    for(int i = 0; i<k; i++){
        cin >> customer;
        for(int j=0; j<n; j++) {
            if (info[j] == customer) {
                info[j] = 0;
                check.erase(remove(check.begin(), check.end(), j), check.end());
                check.erase(remove(check.begin(), check.end(), j+n), check.end());
                flag = false;
                break;
            }
        }
        if(!flag || check.size() == 2*n){
            flag = true;
            continue;
        }
        where_sit(spot, check);
        info[(spot[0] + spot[1]/2)%n] = customer;
        check.push_back((spot[0] + spot[1]/2)%n);
        check.push_back((spot[0] + spot[1]/2)%n+n);
        cout << customer << " " << (spot[0] + spot[1]/2)%n + 1 << endl;
    }
}

int main(void){
    int n = 0, k = 0;
    cin >> n >> k;
    int *info = new int[n]{};
    vector<int> check;

    how_to_sit(n, k, info, check);

    delete[] info;
    return 0;
}