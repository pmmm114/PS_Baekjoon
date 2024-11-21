#include <iostream>

using namespace std;

int N;
long long D[101][10];

int mod = 1000000000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    D[1][1] =
    D[1][2] =
    D[1][3] =
    D[1][4] =
    D[1][5] =
    D[1][6] =
    D[1][7] =
    D[1][8] =
    D[1][9] = 1LL;

    cin >> N;

    for(int i=2;i<=N;i++) {
        for (int k = 0; k <= 9; ++k) {
            if (k != 0) D[i][k] += D[i - 1][k - 1];
            if (k != 9) D[i][k] += D[i - 1][k + 1];
            D[i][k] %= mod;
        }
    }

    long long ans = 0;
    for(int i=0;i<=9;i++) {
        ans += D[N][i];
    }
    ans %= mod;

    cout << ans;
    return 0;
}