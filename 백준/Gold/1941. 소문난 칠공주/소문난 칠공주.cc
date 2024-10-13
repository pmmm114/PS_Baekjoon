#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define X first 
#define Y second

int mask[25];
char students[5][5];

char the_sevens[7];

// 상하좌우
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int ans = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    char student;
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            cin >> student;
            students[i][j] = student;
        }
    }

    // 25C7로 조합을 만들기 위한 mask, 0이 선택할 수
    fill(mask+7, mask+25, 1);

    // 조합 25개 중에 7개를 선택, 25C7
    // combination에 고른 7개를 true로 표시\
    // bfs로 7명 학생이 연결됐는지, 다솜파가 4명인지 확인
    do {
        int visited[5][5] = {0};
        int combination[5][5] = {0};
        queue< pair<int, int> > q;
        
        // bfs 스타팅
        for(int i=0;i<25;i++) {
            if(mask[i] == 0) {
                int position_x = i / 5;
                int position_y = i % 5;
                combination[position_x][position_y] = 1;

                if(q.empty()) {
                    visited[position_x][position_y] = 1;
                    q.push({position_x, position_y});
                }
            }
        }

        int cnt = 0;
        int dasom = 0;
        while(!q.empty()) {
            auto curr = q.front();q.pop();

            cnt++;
            if(students[curr.X][curr.Y] == 'S') dasom++;

            for(int dir=0;dir<4;dir++) {
                int nx = curr.X + dx[dir];
                int ny = curr.Y + dy[dir];

                if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
                if(visited[nx][ny] == 1) continue;
                if(combination[nx][ny] == 0) continue;

                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }

        ans += (dasom >=4 && cnt >= 7);

    } while(next_permutation(mask, mask+25));

    cout << ans;

    return 0;       
}