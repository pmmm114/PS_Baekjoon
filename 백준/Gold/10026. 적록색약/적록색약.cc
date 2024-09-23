// 제한시간 1초
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define X first
#define Y second

char board[101][101];
bool visited[101][101];

// 2차원배열 기준으로 아래, 오른쪽, 위, 왼쪽
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue< pair<int, int> > q;

int N;

void visited_reset() {
    for(int i=0;i<N;i++) {
        fill(visited[i], visited[i]+N, false);
    }
}

void bfs(int x, int y, bool is_weak) {
    visited[x][y] = true;
    q.push(make_pair(x, y));

    while(!q.empty()) {
        auto cur = q.front();q.pop();
        char cur_color = board[cur.X][cur.Y];

        for(int dir=0;dir<4;dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx<0 || nx >= N || ny < 0 || ny >= N) continue;
            if(visited[nx][ny] == true) continue;
            if(is_weak) {
                if(cur_color != board[nx][ny]) {
                    if(cur_color == 'B' || board[nx][ny] == 'B') continue;
                }
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            } else {
                if(cur_color != board[nx][ny]) continue;
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    // 그림 내부값 입력
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> board[i][j];
        }
    }

    int cnt_normal = 0, cnt_weak = 0;
    // 적록색약인 경우
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(!visited[i][j]) {
                bfs(i, j, true);
                cnt_weak++;
            }
        }
    }
    visited_reset();

    // 정상인 경우
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(!visited[i][j]) {
                bfs(i, j, false);
                cnt_normal++;
            }
        }
    }

    cout << cnt_normal << ' ' << cnt_weak << '\n';

    return 0;
}