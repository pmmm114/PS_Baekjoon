#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 상 하 좌 우
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int lab[8][8];
bool visited[8][8];
int N, M;

queue<pair<int, int>> q;

int MAX = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    // 연구실 입력
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> lab[i][j];
        }
    }

    // 크기가 N*M인 1차원 배열 생성
    vector<int> arr(N * M, 1);
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 0;


    int x;
    int y;
    int nx;
    int ny;
    int temp_lab[8][8];
    int safe_zone_cnt;
    do {
        // 실험실 초기화
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                if(lab[i][j] == 2) q.push({i, j});
                temp_lab[i][j] = lab[i][j];
            }
        }

        bool is_skip = false;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == 0) {
                x = i / M;
                y = i % M;

                if(lab[x][y] != 0) {
                    is_skip = true;
                    break;
                }

                temp_lab[x][y] = 1;
            }
        }
        if(is_skip == true) {
            while(!q.empty()) q.pop();
            continue;
        };
        
        while(!q.empty()) {
            auto curr = q.front();q.pop();
            visited[curr.first][curr.second] = true;

            for(int dir=0;dir<4;dir++) {
                nx = curr.first + dx[dir];
                ny = curr.second + dy[dir];

                if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                if(visited[nx][ny] == true) continue;
                if(temp_lab[nx][ny] == 1) continue;

                temp_lab[nx][ny]=2;
                q.push({nx, ny});
            }
        }



        safe_zone_cnt = 0;
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                if(temp_lab[i][j] == 0) safe_zone_cnt++;
            }
        }
        MAX = max(MAX, safe_zone_cnt);

        // 실험실 초기화
        fill(visited[0], visited[0] + 64, false);
    }
    while(next_permutation(arr.begin(), arr.end()));

    cout << MAX;

    return 0;
}