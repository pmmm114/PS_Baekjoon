#include <iostream>

using namespace std;

int N;
int D[1001];
int MOD = 10007;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    D[1]=1;
    D[2]=3;
    cin >> N;

    for(int i=3;i<=N;i++) {
        D[i] = (D[i-1] + D[i-2] + D[i-2]) % MOD; 
    }

    cout << D[N];

    return 0;
}