#include <iostream>

using namespace std;

int map[20][20];
// 주사위 전개도
// [1][1] - 주사위 바닥
// [3][1] - 주사위 윗면
int dice[4][3];
// 동서북남
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int N, M;
// 현재 주사위 위치
int x, y;
int K;

// 1: 동
// 2: 서
// 3: 북
// 4: 남
void move_dice(int dir) {
    int tmp;
    switch (dir)
    {
    case 1:
        tmp = dice[1][0];
        dice[1][0] = dice[1][1];
        dice[1][1] = dice[1][2];
        dice[1][2] = dice[3][1];
        dice[3][1] = tmp;
        break;
     case 2:
        tmp = dice[1][2];
        dice[1][2] = dice[1][1];
        dice[1][1] = dice[1][0];
        dice[1][0] = dice[3][1];
        dice[3][1] = tmp;
        
        break;
    case 3:
        tmp = dice[3][1];
        for(int i=3;i>0;i--) {
            dice[i][1] = dice[i-1][1];
        }
        dice[0][1] = tmp;
        break;
    case 4:
        tmp = dice[0][1];
        for(int i=0;i<3;i++) {
            dice[i][1] = dice[i+1][1]; 
        }
        dice[3][1] = tmp;
        break;
    
    default:
        break;
    }
    
    cout << dice[3][1] << '\n';
}

// 이동할 x, y에
void checker(int dir) {
    dir = dir - 1;
    if(map[x][y] == 0) {
        // 주사위 바닥면을 지도에 복사
        map[x][y] = dice[1+dx[dir]][1+dy[dir]];
    } else {
        dice[1+dx[dir]][1+dy[dir]] = map[x][y];
        map[x][y]=0;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> x >> y >> K;

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> map[i][j];
        }
    }

    int dir;
    int nx;
    int ny;
    for(int i=0;i<K;i++) {
        cin >> dir;

        // 동서남북 이동을 했을 떄
        nx = x + dx[dir-1];
        ny = y + dy[dir-1];

        if(nx < 0 || ny < 0 || nx >= N || ny >= M ) continue;
        
        x = nx;
        y = ny;
        checker(dir);
        move_dice(dir);
    }
    return 0;
}