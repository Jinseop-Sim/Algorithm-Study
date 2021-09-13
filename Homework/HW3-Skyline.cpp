#include <iostream>
#include <algorithm>
using namespace std;

void make_build(int num, int building[][3]){
    int st, h, w = 0;
    for(int i=0;i<num;i++){
        cin >> st >> h >> w;
        building[i][0] = st;
        building[i][1] = h;
        building[i][2] = w;
    }
}

void b_sort(int n, int building[][3]){
    int temp;
    for(int i = n-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (building[j][0] > building[j + 1][0]) {
                for (int k = 0; k < 3; k++) {
                    temp = building[j][k];
                    building[j][k] = building[j + 1][k];
                    building[j + 1][k] = temp;
                }
            }
        }
    }
}

int endpoint(int num, int building[][3]){
    int end_point = 0;
    for(int i = 0; i < num; i++){
        if (end_point < (building[i][0] + building[i][2])) end_point = building[i][0] + building[i][2];
    }
    return end_point;
}

void make_coord(int num, int building[][3], int coord[]){
    int height;
    for(int i = 0; i < num; i++){
        for(int j = 0; j < building[i][2]; j++){
            height = building[i][1];
            if (height > coord[building[i][0] + j]) coord[building[i][0] + j] = height;
            else continue;
            coord[building[i][0] + j] = height;
            }
        }
    }

void print_sky(int end_point, int building[][3], int coord[]){
    int start_point = building[0][0];
    int cnt = 0;
    int height = 0;
    printf("%d ", start_point);
    for(int i = start_point; i <= end_point; i++){
        if (height != coord[i]){
            if (cnt != 0) printf("%d ", cnt);
            printf("%d ", coord[i]-height);
            cnt = 0;
            height = coord[i];
        }
        cnt += 1;
    }
}

int main(){
    int n, end;
    int building[10001][3] = {};

    cin >> n;
    make_build(n, building);
    b_sort(n, building);
    end = endpoint(n, building);

    int *coord = new int[end+1]{0};
    make_coord(n, building, coord);
    print_sky(end, building, coord);

    delete[] coord;
    return 0;
}
