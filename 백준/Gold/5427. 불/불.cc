#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define X first
#define Y second

int building[1002][1002];
int visitedFire[1002][1002];
int visitedHuman[1002][1002];

// 상 하 좌 우
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int T;
int w, h;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while(T--) {
        bool isEscape = false;
        queue<pair<int,int>> firesQ={}, humanQ={};

        cin >> w >> h;

        // 리셋
        for(int i=0;i<1002;i++) {
            fill(building[i], building[i] + 1002, 0);
            fill(visitedFire[i], visitedFire[i] + 1002, 0);
            fill(visitedHuman[i], visitedHuman[i] + 1002, 0);
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                char c;
                cin >> c;
                if (c == '#') building[i][j] = -1;
                else {
                    if (c == '@') {
                        humanQ.push({i, j});
                        visitedHuman[i][j] = 1;
                    } 
                    else if (c == '*') {
                        firesQ.push({i, j});
                        visitedFire[i][j] = 1;
                    }
                    building[i][j] = 0;
                }
            }
        }

        // 화재 경로 이동 및 초 체크
        while(!firesQ.empty()) {
            auto curr_fire = firesQ.front();firesQ.pop();

            for(int dir=0;dir<4;dir++) {
                int nx=curr_fire.X + dx[dir];
                int ny=curr_fire.Y + dy[dir];

                if(nx < 0 || ny < 0 || nx >= h || ny >= w ) continue;
                if(building[nx][ny] == -1) continue;
                if(visitedFire[nx][ny]) continue;
                visitedFire[nx][ny] = visitedFire[curr_fire.X][curr_fire.Y] + 1;
                firesQ.push(make_pair(nx, ny));
            }
        }

        while(!humanQ.empty() && isEscape == false) {
            auto curr_human = humanQ.front();humanQ.pop();

            for(int dir=0;dir<4;dir++) {
                int nx = curr_human.X + dx[dir];
                int ny = curr_human.Y + dy[dir];

                if(nx < 0 || ny < 0 || nx >= h || ny >= w ) {
                    cout << visitedHuman[curr_human.X][curr_human.Y] << '\n';
                    isEscape = true;
                    break;
                };
                if(building[nx][ny] == -1) continue;
                if(visitedHuman[nx][ny]) continue;
                if(visitedFire[nx][ny] != 0 && visitedFire[nx][ny] <= visitedHuman[curr_human.X][curr_human.Y] + 1) continue;
                visitedHuman[nx][ny] = visitedHuman[curr_human.X][curr_human.Y] + 1;
                humanQ.push(make_pair(nx, ny));
            }
        }
        if (!isEscape) cout << "IMPOSSIBLE" << '\n';
    }
}
