#include <iostream>
#include <algorithm>

using namespace std;

int T;
// 현재 사용되는 코인 종류
int coins[10001];
int D[10001];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    int N, M;
    while(T--) {
        fill(coins, coins+10001, 0);
        fill(D, D+10001, 0);

        cin >> N;
        for(int i=0;i<N;i++) {
            cin >> coins[i];
        }

        
        cin >> M;
        D[0] = 1;
        for(int i=0;i<N;i++) {
            for(int j=coins[i];j<=M;j++) {
                D[j] = D[j] + D[j - coins[i]];
            }
        }
        cout << D[M] << '\n';
    }


    return 0;
}