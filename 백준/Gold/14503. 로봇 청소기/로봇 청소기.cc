#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int room[50][50];
bool room_state[50][50];

// 북 동 남 서
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M;
// 0인 경우 북쪽, 
// 3인 경우 서쪽
// 2인 경우 남쪽, 
// 1인 경우 동쪽, 
int robot_x, robot_y, robot_dir;
// 가장 첫번째에 있는게 현재 방향
queue<int> robot_dir_q;

int ans = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    cin >> robot_x >> robot_y >> robot_dir;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> room[i][j];
        }
    }

    // 현재 방향 조절
    robot_dir_q = queue<int>({0, 3, 2 ,1});
    while(robot_dir_q.front() != robot_dir) {
        robot_dir_q.push(robot_dir_q.front());
        robot_dir_q.pop();
    }

    // 로봇 첫위치
    room_state[robot_x][robot_y] = true;

    while(1) {
        room_state[robot_x][robot_y] = true;

        auto curr_x = robot_x;
        auto curr_y = robot_y;

        bool can_clean = false;
        for(int dir=0;dir<4;dir++) {
            // 회전 90도
            robot_dir_q.push(robot_dir_q.front());
            robot_dir_q.pop();
            auto _robot_dir = robot_dir_q.front();

            int nx = curr_x + dx[_robot_dir];
            int ny = curr_y + dy[_robot_dir];

            // 청소가 가능한 경우
            if(room[nx][ny] == 0 && room_state[nx][ny] == false) {
                robot_x += dx[_robot_dir];
                robot_y += dy[_robot_dir];
                can_clean = true;
                break;
            }
        }

        if(can_clean) continue;

        auto _robot_dir = robot_dir_q.front();
        // 뒤로가기
        if(room[curr_x - dx[_robot_dir]][curr_y - dy[_robot_dir]] == 1) break;
        robot_x -= dx[_robot_dir];
        robot_y -= dy[_robot_dir];
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(room_state[i][j] == true) {
                ans += 1;
            }
        }
    }

    cout << ans;

    return 0;
}