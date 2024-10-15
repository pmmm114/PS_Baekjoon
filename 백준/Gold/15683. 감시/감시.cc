#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int office[8][8];
int is_show[8][8];
vector<pair<int, int>> cameras;

// 상하좌우
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};


int N, M;

int ans = 999;

int check_unsafe_zone() {
    int unsafe_zone_cnt = 0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(office[i][j] == 6) continue;
            if(is_show[i][j] == 0) unsafe_zone_cnt++;
        }
    }

    return unsafe_zone_cnt;
}

void update(int x, int y, int dir) {
    is_show[x][y] = 1;

    dir %= 4;
    while (true) {
        x += dx[dir];
        y += dy[dir];
        if (x < 0 || x >= N || y < 0 || y >= M || office[x][y] == 6) return;
        if (office[x][y] != 0) continue;
        is_show[x][y] = 1;
    }
}

// camera[k] 번째 카메라를 백트래킹
void back_tracking( int k ) {
    // 종료조건
    if (k == cameras.size()) {
        ans = min(ans, check_unsafe_zone());
        return;
    }

    int x = cameras[k].first;
    int y = cameras[k].second;
    int type = office[x][y];

    int tmp[8][8];
    // 현재 상태 저장
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            tmp[i][j] = is_show[i][j];

    for (int dir = 0; dir < 4; dir++) {
        // 카메라 타입에 따라 감시 방향 설정
        if (type == 1) {
            update(x, y, dir);
        } else if (type == 2) {
            if(dir == 0 || dir == 1) {
                update(x, y, 0);
                update(x, y, 1);
            } else {
                update(x, y, 2);
                update(x, y, 3);
            }
        } else if (type == 3) {
            if(dir == 0) {
                // 상 우
                update(x, y, 0);
                update(x, y, 3);
            } else if(dir == 1) {
                // 우하
                update(x, y, 3);
                update(x, y, 1);
            } else if(dir == 2) {
                // 하좌
                update(x, y, 1);
                update(x, y, 2);
            } else if(dir == 3) {
                // 상좌
                update(x, y, 0);
                update(x, y, 2);
            }
        } else if (type == 4) {
            update(x, y, dir);
            update(x, y, dir + 1);
            update(x, y, dir + 2);
        } else if (type == 5) {
            update(x, y, dir);
            update(x, y, dir + 1);
            update(x, y, dir + 2);
            update(x, y, dir + 3);
        }

        back_tracking(k + 1);

        // 상태 복원
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                is_show[i][j] = tmp[i][j];
    }
}

// CCTV 최대 개수 8개
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    int num;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> num;
            office[i][j] = num;
        }
    }
    // 감시하고 있는 시야에 벽이 있으면 90도 회전

    // 카메라 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (1 <= office[i][j] && office[i][j] <= 5) {
                cameras.push_back({i, j});
            }
        }
    }

    back_tracking(0);

    cout << ans;
    return 0;
}