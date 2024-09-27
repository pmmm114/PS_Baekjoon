#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int N, M;
char arr[1000][1000];
// 0 = 안쓰는 구역, -1 = 행렬 범위 안
int dist[1000][1000][2];

queue< tuple<int, int, int> > q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> arr[i][j];
            dist[i][j][0] = dist[i][j][1] = -1;
        }
    }

    dist[0][0][0] = dist[0][0][1] = 1;
    q.push({0,0,0});

    while(!q.empty()) {
        int x, y, broken;
        tie(x, y, broken) = q.front();q.pop();

        // 종료조
        // 행렬끝에 도달할 경우 현재 누산값을 리턴
        if(x == N-1 && y == M-1) {
            cout << dist[x][y][broken] << '\n'; 
            return 0;
        }

        for(int dir=0;dir<4;dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            // 범위를 벗어난 경우
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            // 그냥 이동
            if(arr[nx][ny] == '0' && dist[nx][ny][broken] == -1) {
                dist[nx][ny][broken] = dist[x][y][broken] + 1; 
                q.push({nx,ny,broken});
            }
            // 벽을 깨고 이동
            if(!broken && arr[nx][ny] == '1' && dist[nx][ny][broken] == -1) {
                dist[nx][ny][1] = dist[x][y][broken] + 1; 
                q.push({nx,ny,1});
            }
        }
    }

    cout << -1 << '\n';
    return 0;
}