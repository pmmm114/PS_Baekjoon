// 제한시간 2초
// 최단 시간이기 떄문에 순간이동을 하는 경우가 우선되어야함
#include <iostream>
#include <queue>

using namespace std;


// 0 이상, 100,000이하
int N, K;

// 동생 위치 -1, 방문하면 해당 위치까지 걸린 시간, 
int position[100001];

queue< int > q;

int move_dir[2] = {-1, 1};


void teleport(int p) {
    auto warp = p * 2;
    if (warp == 0) return;

    while(warp < 100001) {
        if(position[warp] == 0) {
            position[warp] = position[p];
            q.push(warp);
            if(warp == K) return;
        }
        warp *= 2;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    // 수빈의 첫위치
    position[N] = 1;
    q.push(N);
    teleport(N);

    // +1, -1 
    while(!position[K]) {
        auto curr = q.front();q.pop();

        for(int i=0;i<2;i++) {
            int nmoving = curr + move_dir[i];

            if(nmoving < 0 || nmoving >= 100001) continue;
            if(position[nmoving] != 0) continue;

            position[nmoving] = position[curr] + 1;
            q.push(nmoving);
            teleport(nmoving);
        }
    }

    cout << position[K] - 1;

    return 0;
}