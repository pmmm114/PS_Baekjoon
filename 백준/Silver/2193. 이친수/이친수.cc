#include <iostream>

using namespace std;

int N;
long long D[91][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    D[1][0] = 0;
    D[1][1] = 1LL;

    for(int i=2;i<=N;i++) {
        D[i][0] = D[i-1][1] + D[i-1][0];
        D[i][1] = D[i-1][0];
    }

    cout << D[N][0]+D[N][1];

    return 0;
}