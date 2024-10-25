#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>

using namespace std;

int board[105][105];

// 동 남 서 북
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int N, K, L;

// 동:0, 남:1, 서:2, 북:3
int snake_dir = 0;

int duration = 0;

queue<pair<int, char>> snake_L;
deque<pair<int, int>> snake_dq;

void set_snake_on_board() {
    deque<pair<int, int>> temp_snake_dq = snake_dq;

    for(int i=0;i<=N;i++) {
        for(int j=0;j<=N;j++) {
            if(board[i][j] != 2) board[i][j] = 0;
        }
    }
    while(!temp_snake_dq.empty()) {
        auto curr = temp_snake_dq.front();temp_snake_dq.pop_front();

        board[curr.first][curr.second] = 1;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cin >> K;

    int x, y;
    for(int i=0;i<K;i++) {
        cin >> x >> y;
        // 사과 위치
        board[x][y] = 2;
    }
    cin >> L;
    int time;
    char dir;
    for(int i=0;i<L;i++) {
        cin >> time >> dir;
        snake_L.push({ time, dir }); 
    }

    snake_dq.push_front({1, 1});

    while(true) {
        set_snake_on_board();

        // 방향 전환 시간 체크
        auto next_dir = snake_L.front();
        
        if(next_dir.first == duration) {
            switch (next_dir.second)
            {
            case 'L':
                snake_dir = (snake_dir - 1 + 4) % 4;
                break;
            case 'D':
                snake_dir = (snake_dir + 1) % 4;
                break;
            default:
                break;
            }
            snake_L.pop();
        }

        auto curr_head = snake_dq.front();
        int nx = curr_head.first + dx[snake_dir];
        int ny = curr_head.second + dy[snake_dir];

        // 게임종료 조건
        if( nx < 1 || ny < 1 || nx > N || ny > N ) {
            duration++;
            break;
        };
        // 몸에 닿는 경우 체크
        if(board[nx][ny] == 1) {
            duration++;
            break;
        }


        if(board[nx][ny] == 2) {
            // 사과
            board[nx][ny] = 0;
        } else {
            // 일반 이동
            snake_dq.pop_back();
        }
        snake_dq.push_front({nx, ny});
        duration++;
    }

    cout << duration;

    return 0;
}