#include <string>
#include <vector>
using namespace std;

void dfs(int sol, vector<bool>& visit, vector<vector<int>> computers){
    visit[sol] = true;
    for(int i = 0; i<computers.size(); i++){
        if(computers[sol][i] && !visit[i]){
            dfs(i, visit, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<bool> visit(n, 0);
    for(int i = 0; i < n; i++){
        if(!visit[i]){
            answer++;
            dfs(i, visit, computers);
        }
    }
    
    return answer;
}
