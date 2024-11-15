#include <iostream>
#include <algorithm>

using namespace std;

int N;
int S[100001];
int D[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=1;i<=N;i++) {
        cin >> S[i];
    }

    D[1] = S[1];
    for(int i=2;i<=N;i++) {

        if(  D[i-1] <= 0 ) {
            D[i] = S[i];
        } else {
            D[i] = D[i-1] + S[i];
        }
    }

    cout << *max_element(D+1, D+N+1);

    return 0;
}