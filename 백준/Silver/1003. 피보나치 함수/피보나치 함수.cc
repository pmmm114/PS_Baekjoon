#include <iostream>

using namespace std;

int T;
int D[41][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    D[0][0]=1;D[0][1]=0;
    D[1][0]=0;D[1][1]=1;

    for(int i=2;i<=40;i++) {
        D[i][0] = D[i-1][0] + D[i-2][0];
        D[i][1] = D[i-1][1] + D[i-2][1];
    }

    int N;
    while(T--) {
        cin >> N;
        cout << D[N][0] << " " << D[N][1] << '\n';
    }


    return 0;
}