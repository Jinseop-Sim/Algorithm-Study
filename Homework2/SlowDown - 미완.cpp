#include <iostream>
#include <queue>
using namespace std;

int n = 0, t = 0, k = 0;

struct work {
    int price;
    int dead;
};

struct cmp {
    bool operator()(work& a, work& b) {
        return a.price < b.price;
    }
};

priority_queue<work, vector<work>, cmp> table;
priority_queue<work, vector<work>, cmp> rest_table;

void make_table() {
    int p = 0, d = 0;
    for (int i = 0; i < n; i++) {
        work temp;
        cin >> p >> d; temp.price = p; temp.dead = d;
        table.push(temp);
    }
}

void find_max(vector<vector<int>>& profit_table) {
    while (!table.empty()) {
        for (int i = 0; i < k; i++) {
            if (table.empty()) break;
            if (profit_table[i][table.top().dead - 1] != 0) {
                if (i == k - 1) { rest_table.push(table.top()); table.pop(); }
                continue;
            }
            else {
                profit_table[i][table.top().dead - 1] = table.top().price;
                table.pop();
            }
        }
    }

    for (int i = 0; i < k; i++) {
        if (rest_table.empty()) break;
        for (int j = t; j >= 0; j--) {
            work temp;
            if (rest_table.empty()) break;
            if (j <= rest_table.top().dead - 1) {
                if (profit_table[i][j] < rest_table.top().price) {
                    temp.price = profit_table[i][j]; temp.dead = j + 1;
                    profit_table[i][j] = rest_table.top().price;
                    rest_table.pop(); rest_table.push(temp);
                }
            }
        }
    }
}

void find_sec_max(vector<vector<int>>& profit_table) {
    int min_dist = 1000001, save_x = 0, save_y = 0, save_price = 0;
    while (!rest_table.empty()) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < t; j++) {
                if (profit_table[i][j] <= rest_table.top().price) continue;
                if (profit_table[i][j] - rest_table.top().price < min_dist) {
                    min_dist = profit_table[i][j] - rest_table.top().price;
                    save_x = j; save_y = i; save_price = rest_table.top().price;
                }
            }
        }
        rest_table.pop();
    }
    profit_table[save_y][save_x] = save_price;
}

void calc_sum(vector<vector<int>> profit_table) {
    int sum = 0;
    for (auto row : profit_table) {
        for (auto col : row) { cout << col << " "; sum += col; }
        cout << endl;
    }
    cout << sum << endl;
}

int main() {
    cin >> n >> t >> k;
    vector<vector<int>> profit_table(k, vector<int>(t, 0));
    make_table();

    find_max(profit_table);
    calc_sum(profit_table);

    find_sec_max(profit_table);
    calc_sum(profit_table);

    return 0;
}
