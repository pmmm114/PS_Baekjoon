// 시간제한 1초
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
#define X first
#define Y second

// 배추맡
int board[51][51];
// 방문체크
bool visited[51][51];

// 좌표이동
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

// BFS 큐
queue< pair<int, int> > q;

int T;
int M, N, K;


void reset() {
    for(int i=0;i<N;i++) {
        fill(board[i], board[i]+M, 0);
        fill(visited[i], visited[i]+M, false);
    }
}

void bfs(int x, int y) {
    /**
     * 큐에 넣을 때 방문표시
     */
    // 방문표시
    visited[x][y] = true;
    // BFS 큐에 넣기
    q.push(make_pair(x, y));

    // 큐가 빌 때 까지
    while(!q.empty()) {
        auto cur = q.front();q.pop();

        for(int dir=0;dir<4;dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            // 범위를 벗어난 좌표 pass
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            // 방문했거나 배추가 없는 좌표라면 pass
            if(visited[nx][ny] || board[nx][ny] != 1) continue;
            visited[nx][ny] = true;
            q.push(make_pair(nx, ny));
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while(T--) {
        cin >> M >> N >> K;
        
        // 배추 좌표 삽입
        for(int i=0;i<K;i++) {
            int x, y;
            cin >> x >> y;
            board[y][x] = 1;
        }

        int cnt = 0;
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                if(board[i][j] == 1 && !visited[i][j]) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
        reset();
    }
    
    return 0;
}