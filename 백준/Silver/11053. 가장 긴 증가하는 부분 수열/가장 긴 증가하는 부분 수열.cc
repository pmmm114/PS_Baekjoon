#include <iostream>
#include <algorithm>

using namespace std;

int N;
int S[1001];
int D[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i=1;i<=N;i++) {
        cin >> S[i];
        D[i] = 1;
    }

    for(int i=1;i<=N;i++) {
        for(int j=1;j<i;j++) {
            if (S[j] < S[i]) D[i] = max(D[i], D[j] + 1);
        }
    }

    cout << *max_element(D+1, D+1+N);
    return 0;
}
