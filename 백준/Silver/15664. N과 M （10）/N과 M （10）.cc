#include <iostream>
#include <algorithm>

using namespace std;

int sequence[9];
int isused[9];
int num_arr[9];

int N, M;

void back_tracking( int k ) {
    if( k == M ) {
        for(int i=0;i<M;i++) {
            cout << sequence[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int tmp = 0;
    for(int i=0;i<N;i++) {
        if(isused[i] == 0 && tmp != num_arr[i]) {
            if( k != 0 && sequence[k-1] > num_arr[i]) continue;
            
                sequence[k] = num_arr[i];
                isused[i] = 1;
                tmp = sequence[k];
                back_tracking(k+1);
                isused[i] = 0;
        }
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
    sort(num_arr, num_arr + N);

    back_tracking(0);

    return 0;
}