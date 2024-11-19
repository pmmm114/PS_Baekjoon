#include <iostream>

using namespace std;

int T, N;
long long D[101]; 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    D[1] = D[2] = D[3] = 1LL;
    D[4] = D[5] = 2LL;

    cin >> T;

    while(T--) {
        cin >> N;

        if( N > 5 ) {
            for(int i=6;i<=N;i++) {
                D[i] = D[i-1] + D[i-5];
            }
        }

        cout << D[N] << '\n';
    }

    return 0;
}