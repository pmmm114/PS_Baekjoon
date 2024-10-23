#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

// 상 하 좌 우 위 아래
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int input_miro[5][5][5];
int miro[5][5][5];
int dist[5][5][5];
int visited[5][5][5];
queue<tuple<int, int, int>> enterance;
queue<tuple<int, int, int>> q;

vector<int> v;

int ans = 125;

// 1회 요청 시, 시계방향으로 90도 회전
void rotation(int floor) {
    int temp[5][5];
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            temp[j][4-i] = miro[i][j][floor];
        }
    }
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            miro[i][j][floor] = temp[i][j];
        }
    }
}

void bfs() {
    // 초기화
    while(!q.empty()) q.pop();
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 5; ++k) {
                dist[i][j][k] = 0;
                visited[i][j][k] = 0;
            }
        }
    }
    
    // 미로찾기
    while(!enterance.empty()) {
        int enter_x, enter_y, enter_z;
        auto curr_enterance = enterance.front();enterance.pop();
        tie(enter_x, enter_y, enter_z) = curr_enterance;
        int exit_x = 4-enter_x, exit_y = 4-enter_y, exit_z = 4;

        q.push({enter_x, enter_y, enter_z});
        visited[enter_x][enter_y][enter_z] = 1;
        dist[enter_x][enter_y][enter_z] = 0;

        // q 초기화
        while(!q.empty()) {
            int curr_x, curr_y, curr_z;
            auto curr_position = q.front();q.pop();
            tie(curr_x, curr_y, curr_z) = curr_position; 

            for(int dir=0;dir<6;dir++) {
                int nx = curr_x + dx[dir];
                int ny = curr_y + dy[dir];
                int nz = curr_z + dz[dir];

                if(nx < 0 || ny < 0 || nz < 0 || nx >= 5 || ny >= 5 || nz >= 5) continue;
                if(visited[nx][ny][nz] == 1) continue;
                if(miro[nx][ny][nz] == 0 ) continue;

                dist[nx][ny][nz] = dist[curr_x][curr_y][curr_z] + 1;
                visited[nx][ny][nz] = 1;
                q.push({nx, ny, nz});
                if(nx == exit_x && ny == exit_y && nz == exit_z) {
                    v.push_back(dist[exit_x][exit_y][exit_z]);
                    return;
                }
            }
        }
    }
}

void explore(int depth) {
    if (depth == 5) {
        // 출입구와 출구 설정
        //출입구 선정
        for(int i=0;i<5;i+=4) {
            for(int j=0;j<5;j+=4) {
                // 들어갈 수 없는 출입구를 가진 경우
                if( miro[i][j][0] == 0 || miro[4-i][4-j][4] == 0 ) continue;
                enterance.push({i, j, 0});
            }
        }
        bfs();
        return;
    }

    for (int r = 0; r < 4; r++) {
        if (r > 0) rotation(depth);
        explore(depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int floor=0;floor<5;floor++) {
        for(int i=0;i<5;i++) {
            for(int j=0;j<5;j++) {
                cin >> input_miro[i][j][floor];
            }
        }
        
    }

    int order[5] = {0,1,2,3,4};
    do {
        // 층을 재배치
        for(int floor=0; floor<5; floor++) {
            for(int i=0; i<5; i++) {
                for(int j=0; j<5; j++) {
                    miro[i][j][floor] = input_miro[i][j][order[floor]];
                }
            }
        }

        // 재귀를 통해 모든 회전 조합 탐색
        explore(0);
        
    } while(next_permutation(order, order+5));

    for(int i=0;i<v.size();i++) {
        if(v[i] == 0) continue;
        ans = min(ans, v[i]);
    }

    if(ans == 125) {
        cout << -1;
    } else {
        cout << ans;
    }

    return 0;
}