#include <iostream>
#include <algorithm>

using namespace std;

// 상 하 좌 우
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

// 0은 값, 1은 병합 플래그
int board[20][20][2];

// board size
int N;

int MAX = 0;

// 한쪽으로 밀기
// 0 상, 1 하, 2 좌, 3 우
void one_side(int dir) {
    bool reverse = false;
    if(dir == 1 || dir == 3) reverse=true;

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            // 현재 좌표
            int _i = reverse ? (N-1)-i : i;
            int _j = reverse ? (N-1)-j : j;
            if( board[_i][_j][0] == 0) continue;

            // 다음좌표
            int nx = _i + dx[dir];
            int ny = _j + dy[dir];
            while(board[nx][ny][0] == 0) {
                if( nx < 0 || ny < 0 || N <= nx || N <= ny ) break;

                // 다음 좌표로 현재 좌표값을 저장
                board[nx][ny][0] = board[_i][_j][0];
                board[nx][ny][1] = board[_i][_j][1];
                board[_i][_j][0] = 0;
                board[_i][_j][1] = 0;

                _i = nx;
                _j = ny;
                
                nx+=dx[dir];
                ny+=dy[dir];
            }
        }
    }   
}

// 한쪽으로 병합
// 0 상, 1 하, 2 좌, 3 우
void merge(int dir) {
    bool reverse = false;
    if(dir == 1 || dir == 3) reverse=true;

    int _dir;
    if(dir==0) _dir=1;
    else if(dir==1) _dir=0;
    else if(dir==2) _dir=3;
    else if(dir==3) _dir=2;


    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            // 현재 좌표
            int _i = reverse ? (N-1)-i : i;
            int _j = reverse ? (N-1)-j : j;

            // 다음 좌표
            int nx = _i + dx[_dir];
            int ny = _j + dy[_dir];

            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(board[_i][_j][1] == 1) continue;

            if(board[_i][_j][0] == board[nx][ny][0]) {
                board[_i][_j][0] += board[nx][ny][0];
                board[nx][ny][0] = 0;
                board[nx][ny][1] = 1;
                board[_i][_j][1] = 1;
            }
        }
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            board[i][j][1] = 0;
        }
    }
}

// k번째 이동, 0 베이스
void back_tarcking(int k) {
    if( k == 5 ) {
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                MAX = max(MAX, board[i][j][0]);                
            }
        }
        return;
    }

    for(int dir=0;dir<4;dir++) {
        int tmp_prev[20][20][2];
        // 초기값 설정
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                tmp_prev[i][j][0] = board[i][j][0];                
                tmp_prev[i][j][1] = board[i][j][1];                
            }
        }
        // 이동
        one_side(dir);
        // 병합
        merge(dir);
        // 이동
        one_side(dir);
        // 다음시도
        back_tarcking(k+1);
        
        // 초기값 설정
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                board[i][j][0] = tmp_prev[i][j][0];                
                board[i][j][1] = tmp_prev[i][j][1];                
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> board[i][j][0];
            board[i][j][1] = 0;
        }
    }

    back_tarcking(0);

    cout << MAX;

    return 0;
}