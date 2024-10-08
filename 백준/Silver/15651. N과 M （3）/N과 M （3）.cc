#include <iostream>

using namespace std;


int sequence[8];

int N, M;

void back_tracking(int k) {
    if(k == M) {
        for(int i=0;i<M;i++) {
            cout << sequence[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=1;i<=N;i++) {
        sequence[k] = i;
        back_tracking(k+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    back_tracking(0);

    return 0;
}