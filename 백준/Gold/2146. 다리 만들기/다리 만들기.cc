// 제한시간 2초
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define X first
#define Y second

int N;

// 0바다, 1육지
int island[101][101];
int dist[101][101];
int visited[101][101];

// 상 하 좌 우
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

queue< pair<int, int> > q;

int island_num;
int minimum = 10000;


// 섬 구분
void bfs(int x, int y) {
    visited[x][y] = 1;
    island[x][y] = island_num;
    q.push({x, y});

    while(!q.empty()) {
        auto curr = q.front();q.pop();

        for(int dir=0;dir<4;dir++) {
            int nx = curr.X + dx[dir];
            int ny = curr.Y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(visited[nx][ny] == 1 || island[nx][ny] == 0) continue;

            visited[nx][ny] = 1;
            island[nx][ny] = island_num;
            q.push({nx, ny});
        }
    }
}

void find_shortest(int x, int y) {
    // dist 배열 초기화
    for(int i=0; i<N; i++) {
        fill(dist[i], dist[i] + N, -1);
    }

    dist[x][y] = 0;
    q.push({x, y});

    while(!q.empty()) {
        auto curr = q.front();q.pop();
        for(int dir=0;dir<4;dir++) {
            int nx = curr.X + dx[dir];
            int ny = curr.Y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            // 같은 섬좌표는 스킵, 방문했던 곳은 스킵
            // ISSUE. 현재 좌표가 바다고 다음좌표가 바다인 경우에도 스킵이 된다.
            // - 처음시작했던 좌표의 타입과 이동할 좌표의 타입이 같은지 체크
            if(dist[nx][ny] >= 0 || island[x][y] == island[nx][ny]) continue;

            // 다른 섬에 도달한 경우
            if(island[curr.X][curr.Y] != island[nx][ny] && island[nx][ny] != 0) {
                minimum = min(minimum, dist[curr.X][curr.Y]);
                while(!q.empty()) q.pop();
                return;
            }

            // cout << curr.X << "/" << curr.Y << " // " << nx << "/" << ny << "\n";
            dist[nx][ny] = dist[curr.X][curr.Y] + 1;
            q.push({nx, ny});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> island[i][j];
        }
    }

    island_num = 1;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            // 섬 종류 구분
            if(island[i][j] == 1 && visited[i][j] == 0) {
                bfs(i, j);
                island_num++;
            }
        }
    }

    for(int k=0;k<N;k++) {
        fill(dist[k], dist[k] + N, -1);
    }

    // 현재 섬
    // 육지끼리 연결하는 bfs처리
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(island[i][j] != 0) {
                find_shortest(i, j);
                // for(int a=0;a<N;a++) {
                //     for(int b=0;b<N;b++) {
                //         cout << dist[a][b] << " ";
                //     }
                //     cout << "\n";
                // }
                // cout << "------------" << "\n";
            }
        }
    }
    


    cout << minimum;

    return 0;
}