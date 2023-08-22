#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <iostream>

using namespace std;

bool bfs(int x, int y, vector<vector<string>> &place) {
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    bool visited[5][5] = {false};
    queue<pair<pair<int, int>, int>> q;
    visited[x][y] = true;
    q.push({{x, y}, 0});
    
    while(!q.empty()) {
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
    
            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || visited[nx][ny]) continue;
            
            if (place[nx][ny] == "O" && cnt < 2) {
                q.push({{nx, ny}, cnt+1});
                visited[nx][ny] = true;
            } else if (place[nx][ny] == "P") {
                if (abs(nx - x) + abs(ny - y) <= 2) return false;
            }
        }
    }
    
    return true;
}

int find_dist(vector<vector<string>> &place) {
    // i 행, j 열
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            if (place[i][j] == "P") {
                if (!bfs(i, j, place)) return 0;
            }
        }
    }
    
    return 1;    
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int i=0;i<places.size();i++) {
        vector<vector<string>> tmp_all;
        for(int j=0;j<5;j++) {
            vector<string> tmp_row;
            for(int k=0;k<places[i][j].length();k++) {
                tmp_row.push_back(string(1, places[i][j][k]));
            }
            tmp_all.push_back(tmp_row);
        }
        int result = find_dist(tmp_all);
        answer.push_back(result);
    }
    
    return answer;
}