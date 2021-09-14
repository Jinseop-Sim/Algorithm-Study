#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void func_input(int num, int xarray[], int yarray[], int time[]){ // 입력 함수이다.
    int x, y, t;
    for(int i = 0; i < num; i++){
        cin >> x >> y;
        xarray[i] = x;
        yarray[i] = y;
    }

    for (int i = 0; i < 5; i++){
        cin >> t;
        time[i] = t;
    }
}

void make_map(int num, int xarray[], int yarray[], vector<vector<int>> &check, vector<int> temp){ // 여기부터 좌표를 만드는 함수이다.
    for(int i = 1; i < (num+1); i++){  // 다음 x좌표가 이전 x좌표와 다르면 그 사이의 정수들을 모두 저장하는 반복문이다.
        if (xarray[i] != xarray[i-1]){
            if (xarray[i] > xarray[i-1]){ // 이 분기는 음수 좌표를 만들지 않기 위해서 더 큰 쪽에서 작은 쪽으로 연산시키기 위함이다.
                for(int j = xarray[i-1]; j < xarray[i]; j++){
                    temp[0] = j;
                    temp[1] = yarray[i-1];
                    check.push_back(temp);
                }
            }
            else{
                for(int j = xarray[i-1]; j > xarray[i]; j--){ // 이 for문이 거꾸로 가는 이유는 좌표가 큰 곳에서 작은 곳으로 내려가기 때문이다.
                    temp[0] = j;
                    temp[1] = yarray[i-1];
                    check.push_back(temp);
                }
            }
        }
        else if (yarray[i] != yarray[i-1]){  // 다음 y좌표가 이전 y좌표와 다르면 그 사이의 정수들을 모두 저장하는 반복문이다.
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

void print_answer(vector<vector<int>> &check, int time[]){ // 1초마다의 위치를 check vector에 저장을 해 놓았으니 원하는 시간의 위치를 check의 길이와 mod 연산해 얻는다.
    for(int i=0; i < 5; i++){
        cout << check[time[i]%check.size()][0] << " " << check[time[i]%check.size()][1] << endl;
    }
}

int main(void){
    int k;
    cin >> k;
    int time[5];

    int *xarray = new int[k+1]; // x좌표와 y좌표는 k개 만큼 받아야 하므로 동적 메모리 할당을 해준다.
    int *yarray = new int[k+1];

    vector<vector<int>> check;
    vector<int> temp(2,0);

    func_input(k, xarray, yarray, time);
    xarray[k] = xarray[0];
    yarray[k] = yarray[0];
    make_map(k, xarray, yarray, check, temp);
    print_answer(check, time);

    delete[] xarray;
    delete[] yarray;

    return 0;
}
