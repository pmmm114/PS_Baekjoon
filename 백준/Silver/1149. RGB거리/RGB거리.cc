#include <iostream>
#include <algorithm>

using namespace std;

int D[1002][3];
int S[1002][3];
// 최소값 2
int N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=1;i<=N;i++) {
        cin >> S[i][0] >> S[i][1] >> S[i][2];
    }

    // 초기값 설정
    D[1][0]= S[1][0];
    D[1][1]= S[1][1];
    D[1][2]= S[1][2];

    for(int i=2;i<=N;i++) {
        D[i][0] = min(D[i-1][1], D[i-1][2]) + S[i][0];
        D[i][1] = min(D[i-1][0], D[i-1][2]) + S[i][1];
        D[i][2] = min(D[i-1][0], D[i-1][1]) + S[i][2];
    }

    cout << min(D[N][0], min(D[N][1], D[N][2]));

    return 0;
}