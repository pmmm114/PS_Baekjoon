#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

char field[12][6];
bool visited[12][6];

// 상하좌우
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

queue<pair<int, int>> q;
vector<vector<pair<int, int>>> v;

// 연쇄 카운트
int cnt = 0;
// 현재 구슬이 터진지 여부
int is_chain = false;

void fall_puyo() {
    // 아래부터 연산시작을 진행하며
    for(int i=11;i>=0;i--) {
        for(int j=0;j<6;j++) {
            if(field[i][j] == '.') continue;
            
            int nx = i + 1;
            int ny = j;
            if(field[nx][ny] != '.') continue;

            while(
                field[nx][ny] == '.'
            ) {
                if(nx < 0 || ny < 0 || 12 <= nx || 6 <= ny) break;
                if(field[nx][ny] != '.') break;
                nx++;
            }

            field[nx-1][ny] = field[i][j];
            field[i][j] = '.';
        }
    }
}

void bfs(char color) {
    char curr_color = color;
    vector<pair<int, int>> _v;

    while(!q.empty()) {
        auto curr = q.front();q.pop();
        
        _v.push_back({curr.first, curr.second});

        for(int dir=0;dir<4;dir++) {
            int nx = curr.first + dx[dir];
            int ny = curr.second + dy[dir];

            if(nx < 0 || ny < 0 || 12 <= nx || 6 <= ny) continue;
            if(visited[nx][ny]) continue;
            if(field[nx][ny] == '.') continue;

            if(field[nx][ny] == curr_color) {
                q.push({nx, ny});
                visited[curr.first][curr.second] = true;
            };
        }
    }

    if(_v.size() >= 4) {
        v.push_back(_v);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0;i<12;i++) {
        for(int j=0;j<6;j++) {
            cin >> field[i][j];
        }
    }

    int _tmp;
    do {
        _tmp = cnt;
        is_chain = false;
        for(int i=0;i<12;i++) {
            for(int j=0;j<6;j++) {
                if(field[i][j] == '.' || visited[i][j] == true) continue;
                q.push({i, j});
                visited[i][j] = true;
                bfs(field[i][j]);
            }
        }

        // 연쇄된 구슬 제거 및 플래그 설정
        if(v.size() > 0) is_chain = true;
        for(int i=0;i<v.size();i++) {
            for(int j=0;j<v[i].size();j++) {
                field[v[i][j].first][v[i][j].second] = '.';
            }
        }
        v.clear();
        
        if(is_chain == true) cnt++;

        // 구슬 추락
        fall_puyo();
        
        // visited 초기화
        fill(visited[0], visited[0]+(12*6), false);
    } while( _tmp != cnt );

    cout << cnt;

    return 0;
}

