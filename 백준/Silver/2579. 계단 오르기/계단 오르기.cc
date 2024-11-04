#include <iostream>
#include <algorithm>

using namespace std;

int N;
int S[305];
int D[305][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i=1;i<=N;i++) {
        cin >> S[i];
    }

    if(N == 1) {
        cout << S[1];
        return 0;
    }

    // 초기값 설정
    D[1][1] = S[1];
    D[1][2] = 0;
    D[2][1] = S[2];
    D[2][2] = S[1] + S[2];

    for(int i=3;i<=N;i++) {
        D[i][1]  = max( D[i-2][2],  D[i-2][1] ) + S[i];
	    D[i][2] = D[i-1][1] + S[i];
    }

    cout << max(D[N][1], D[N][2]);

    return 0;
}