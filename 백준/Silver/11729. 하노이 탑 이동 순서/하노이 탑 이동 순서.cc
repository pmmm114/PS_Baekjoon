#include <iostream>
#include <queue>
#include <utility>

using namespace std;

// 귀납적 추론
// 1. 1번에서 n-1개를 3번 장대를 거쳐 2번으로 이동
// 2. 1번 장대의 n번 장대를 3번으로 이동
// 3. 2번 장대의 n-1개의 원판을 1번을 거쳐 3번으로 이동

int cnt;

queue<pair<int, int>> Q;

// n개의 원판을 a기둥에서 b기둥으로 이동
void hano(int a, int b, int n) {
    // BASE CONDITION: 마지막 이동
    if(n == 1) {
        cnt++;
        Q.push({a, b});
        return;
    };

    // 1. a -> b로 옮기기 위해 나머지 장대에 n-1개 이동 
    hano(a, 6-a-b, n-1);
    // 2. a -> b로 옮기기 위해 n번 장대를 b로 이동
    cnt++;
    Q.push({a, b});
    // 3. 나머지 장대의 원판을 b장대에 n-1개 이동
    hano(6-a-b, b, n-1);
}

// k개를 옮기기 위해 A번
// k+1개를 옮기기 위해선 k를 빈곳으로 A번, k+1번원 판 목적지로 1번 이동, 빈 곳에 있던 k를 다시 목직지로 A번
// 2A+1 번


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin.tie(0);

    int N;

    // 원판 개수
    cin >> N;

    cnt = 0;
    // 1번 장대에서 3번 장대로 이동
    hano(1, 3, N);
    cout << cnt<< '\n';

    while(!Q.empty()) {
        pair<int, int> cur = Q.front();Q.pop(); 
        cout << cur.first << ' ' << cur.second << '\n'; 
    }

    return 0;
}