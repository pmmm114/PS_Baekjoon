// 제한시간 1초
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define X first
#define Y second

int board[305][305];

// 현재위치에서 움직일 수 있는 위치
int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, -2, -1, 1, 2};


queue< pair<int, int> > q;

int T;
int I;
pair<int, int> curr;
pair<int, int> target;

void bfs(int x, int y) {

    while(!q.empty()) {
        auto bfs_curr = q.front();q.pop();
        if (bfs_curr == target) return; // 목표 위치에 도달하면 종료
    
        for(int dir=0;dir<8;dir++) {
            int nx = bfs_curr.X + dx[dir];
            int ny = bfs_curr.Y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= I || ny >= I) continue;
            // 동일한 곳 이동 하지 않기
            if (board[nx][ny] >= 0) continue;

            board[nx][ny] = board[bfs_curr.X][bfs_curr.Y] + 1; 
            q.push(make_pair(nx, ny));
        }
    }
}

void reset() {
    for(int i=0;i<I;i++) {
        fill(board[i], board[i]+I, -1);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    

    while(T--) {
        cin >> I;
        cin >> curr.X >> curr.Y;
        cin >> target.X >> target.Y;
    
        // 보드 초기화
        reset();
        
        // 초기 좌표
        board[curr.X][curr.Y] = 0;
        q.push(make_pair(curr.X, curr.Y));

        bfs(curr.X, curr.Y);
        while(!q.empty()) {
            q.pop();
        }

        // 결과 출력
        cout << board[target.X][target.Y] << '\n';
    }
}