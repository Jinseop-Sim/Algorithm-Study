#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

string answer;
int iter = 0;
void make_cartesian(int currX, int currY, int length, vector<vector<string>>& map, vector<char> &text) {
    if (length == 1) {
        map[currY][currX] = text[iter];
        iter++;
        return;
    }
    make_cartesian(currX + length / 2, currY, length / 2, map, text); //1사
    make_cartesian(currX, currY, length / 2, map, text); // 2사
    make_cartesian(currX, currY + length / 2, length / 2, map, text); // 3사
    make_cartesian(currX + length / 2, currY + length / 2, length / 2, map, text); // 4사
}
void check_cartesian(int currX, int currY, int length, vector<vector<string>>& map) {
    bool check = true;
    string curr = map[currY][currX];
    if (length == 1) check = true;
    else {
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                if (curr != map[currY + i][currX + j]) {
                    check = false; break;
                }
            }
            if (!check) break;
        }
    }
    if (check) {
        if (curr == "0") answer += "0";
        else answer += "1";
    }
    else {
        answer += "(";
        check_cartesian(currX + length / 2, currY, length / 2, map); //1사
        check_cartesian(currX, currY, length / 2, map); // 2사
        check_cartesian(currX, currY + length / 2, length / 2, map); // 3사
        check_cartesian(currX + length / 2, currY + length / 2, length / 2, map); // 4사
        answer += ")";
    }
}
void img_to_qts(int map_num, vector<vector<string>>& map) {
    string img;
    for (int i = 0; i < map_num; i++) {
        cin >> img;
        for (int j = 0; j < map_num; j++) {
            map[i][j] = img[j];
        }
    }
    check_cartesian(0, 0, map_num, map);
    cout << answer;
}
void qts_to_img(int depth_limit, int map_num, vector<vector<string>> &map, vector<char> &text) {
    int depth = 0;
    string qts;
    cin >> qts;
    for (int i = 0; i < qts.length(); i++) {
        if (qts[i] == '(') depth++;
        if (qts[i] == ')') depth--;
        if ((qts[i] != '(' && qts[i] != ')') && depth == depth_limit) text.push_back(qts[i]);
        if ((qts[i] != '(' && qts[i] != ')') && depth != depth_limit)
            for (int k = 0; k < pow(4, depth_limit - depth); k++) text.push_back(qts[i]);
    }
    if (qts[0] != '(') {
        for (int i = 0; i < map_num; i++)
            for (int j = 0; j < map_num; j++)  map[i][j] = qts[0];
    }
    else make_cartesian(0, 0, map_num, map, text);
    for (int i = 0; i < map_num; i++) {
        if (i != 0) cout << endl;
        for (int j = 0; j < map_num; j++) cout << map[i][j];
    }
}
int main() {
    int k = 0, map_num = 0;
    string ext;
    cin >> k >> ext;
    map_num = pow(2, k);
    vector<vector <string>> map(map_num, vector<string>(map_num));
    vector<char> text;
    if (ext == "QTS") qts_to_img(k, map_num, map, text);
    else if (ext == "IMG") img_to_qts(map_num, map);
}
