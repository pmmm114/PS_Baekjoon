#include <iostream>
#include <algorithm>

using namespace std;

int N;
int T[1500001];
int P[1500001];
long long D[1500001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i=1;i<=N;i++) {
        cin >> T[i] >> P[i];  
    }

    for(int i = 1; i <= N; i++) {
        // 이전 날의 최대 수익을 현재 날로 전달
        D[i] = max(D[i], D[i-1]);

        // i번째 날에 상담을 할 수 있는 경우
        if (i + T[i] <= N + 1) {
            D[i + T[i] - 1] = max(D[i + T[i] - 1], D[i-1] + P[i]);
        }
    }

    
    cout << *max_element(D + 1, D + 1 + N);

    return 0;
}