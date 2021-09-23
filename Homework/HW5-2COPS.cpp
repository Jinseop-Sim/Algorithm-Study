#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void func_input(int num, int xarray[], int yarray[]){
    int x, y;
    for(int i = 0; i < num; i++) {
        cin >> x >> y;
        xarray[i] = x;
        yarray[i] = y;
    }
}
void make_map(int num, int xarray[], int yarray[], vector<vector<int>> &check, vector<int> temp){ // Robocop 때와 동일한 Map을 그리는 함수이다.
    for(int i = 1; i < (num+1); i++){
        if (xarray[i] != xarray[i-1]){
            if (xarray[i] > xarray[i-1]){
                for(int j = xarray[i-1]; j < xarray[i]; j++){
                    temp[0] = j;
                    temp[1] = yarray[i-1];
                    check.push_back(temp);
                }
            }
            else{
                for(int j = xarray[i-1]; j > xarray[i]; j--){
                    temp[0] = j;
                    temp[1] = yarray[i-1];
                    check.push_back(temp);
                }
            }
        }
        else if (yarray[i] != yarray[i-1]){
            if (yarray[i] > yarray[i-1]){
                for (int j = yarray[i-1]; j < yarray[i]; j++){
                    temp[0] = xarray[i-1];
                    temp[1] = j;
                    check.push_back(temp);
                }
            }
            else{
                for(int j = yarray[i-1]; j > yarray[i]; j--) {
                    temp[0] = xarray[i-1];
                    temp[1] = j;
                    check.push_back(temp);
                }
            }
        }
    }
}
void find_c2(int num, int c1_xarray[], int c1_yarray[], int c2_xarray[], int c2_yarray[]){ // 로봇 C2는 시작점이 다르므로, C2의 시작점을 구하는 함수이다.
    int start = num / 2 - 1;
    for(int i = 0; i < num/2 ; i++){
        c2_xarray[i] = c1_xarray[start];
        c2_yarray[i] = c1_yarray[start];
        start--;
    }
    int end = num / 2;
    for(int i = num - 1; i >= num/2 ; i--){
        c2_xarray[i] = c1_xarray[end];
        c2_yarray[i] = c1_yarray[end];
        end++;
    }
}
void collision(vector<vector<int>> &check, vector<vector<int>> &c2_check){
    int x, y;
    for(int i=0; i<check.size()-1; i++){
        if(check[i] == c2_check[i] || check[i] == c2_check[i+1]){
            for(int j=i; j<check.size()-1; j++){
                x = check[j+1][0]; y = check[j+1][1];
                check[j+1][0] = c2_check[j+1][0]; check[j+1][1] = c2_check[j+1][1];
                c2_check[j+1][0] = x; c2_check[j+1][1] = y;
            }
        }
    }
}
void print_answer(int time, vector <vector <int>> &check, vector <vector <int>> &c2_check){
    cout << check[time % check.size()][0] << " " << check[time % check.size()][1] << endl;
    cout << c2_check[time % c2_check.size()][0] << " " << c2_check[time % c2_check.size()][1] << endl;
}
int main(void){
    int k;
    cin >> k;
    int time = 0;
    int *xarray = new int[k+1];
    int *yarray = new int[k+1];
    int *c2_xarray = new int[k+1];
    int *c2_yarray = new int[k+1];
    vector<vector<int>> check;
    vector<vector<int>> c2_check;
    vector<int> temp(2,0);
    func_input(k, xarray, yarray);
    find_c2(k, xarray, yarray, c2_xarray, c2_yarray);
    cin >> time;
    xarray[k] = xarray[0];
    yarray[k] = yarray[0];
    c2_xarray[k] = c2_xarray[0];
    c2_yarray[k] = c2_yarray[0];
    make_map(k, xarray, yarray, check, temp);
    make_map(k, c2_xarray, c2_yarray, c2_check, temp);
    collision(check, c2_check);
    print_answer(time, check, c2_check);
    delete[] xarray;
    delete[] yarray;
    delete[] c2_xarray;
    delete[] c2_yarray;
    return 0;
}

// 상당히 고난이도의 문제였다.
