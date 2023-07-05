#include <iostream>

// D[i]는 i를 만드는 경우의 수
// D[1] = (1)
// D[2] = (1+1, 2)
// D[3] = (1+1+1, 1+2, 2+1, 3)

// D[4] = 
// (1+1+1+1, 1+2+1, 2+1+1, 3+1) + => (D[3]+1의 수열) = D[3]
// (1+1+2, 2+2) + => (D[2]+2의 수열) = D[2]
// (1+3) => (D[1]+3의 수열) = D[1]

using namespace std;

int DP[12];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    DP[1]=1;DP[2]=2;DP[3]=4;
    
    for(int i=4;i<12;i++) {
        DP[i] = DP[i-1] + DP[i-2] + DP[i-3];
    }

    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;
        cout << DP[N] << '\n';
    }

    return 0;
}