#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n = 0, t = 0, k = 0, g_max = 0;
struct work {
    int price;
    int dead;
};

bool compare(work a, work b) {
    if (a.dead == b.dead) return a.price > b.price;
    return a.dead > b.dead;
}

vector<work> table;
void make_table(vector<vector<work>>& profit_table) {
    int p = 0, d = 0;
    for (int i = 0; i < n; i++) {
        work temp;
        cin >> p >> d; temp.price = p; temp.dead = d;
        table.push_back(temp);
    }

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < k; j++) {
            profit_table[j][i].price = 0;
            profit_table[j][i].dead = i + 1;
        }
    }
    sort(table.begin(), table.end(), compare);
}

void find_max(vector<vector<work>>& profit_table) {
    work temp;
    for (int i = t-1; i >= 0; i--) {
        for (int j = 0; j < k; j++) {
            for (int k = 0; k < table.size(); k++) {
                if (table[k].dead < i+1) break;
                if (table[k].dead >= i+1 && profit_table[j][i].price < table[k].price) {
                    temp = profit_table[j][i];
                    profit_table[j][i] = table[k];
                    table[k] = temp;
                }
            }
        }
    }
}

int calc_sum(vector<vector<work>> profit_table) {
    int sum = 0;
    for (auto row : profit_table) for (auto col : row) sum += col.price;
    return sum;
}

int find_sec_max(vector<vector<work>>& profit_table) {
    int sec_max = 0, inner_max = 0;
    work temp;
    for (int i = 0; i < table.size(); i++) {
        for (int j = 0; j < t; j++) {
            for (int m = 0; m < k; m++) {
                if (table[i].dead >= j + 1) {
                    temp = profit_table[m][j];
                    profit_table[m][j] = table[i];
                    table[i] = temp;
                    inner_max = calc_sum(profit_table);
                    if (inner_max > sec_max && inner_max < g_max) sec_max = inner_max;
                    temp = profit_table[m][j];
                    profit_table[m][j] = table[i];
                    table[i] = temp;
                }
            }
        }
    }
    return sec_max;
}

int main() {
    cin >> n >> t >> k;
    vector<vector<work>> profit_table(k, vector<work>(t));
    make_table(profit_table);

    find_max(profit_table);

    g_max = calc_sum(profit_table);
    cout << g_max << " ";
    
    cout << find_sec_max(profit_table);
    return 0;
}
