#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int sequence[8];
int num_arr[8];

void back_tracking( int k ) {
    if( k == M ) {
        for(int i=0;i<M;i++) {
            cout << sequence[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=0;i<N;i++) {
        sequence[k] = num_arr[i];
        back_tracking(k+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    int num;
    for(int i=0;i<N;i++) {
        cin >> num;
        num_arr[i] = num;
    }
    sort(num_arr, num_arr+N);

    back_tracking(0);

    return 0;
}