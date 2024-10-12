#include <iostream>
#include <algorithm>

using namespace std;

int sequence[9];
int num_arr[9];
int isused[9];

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
            sequence[k] = num_arr[i];
            isused[i] = 1;
            tmp = sequence[k];
            back_tracking(k + 1);
            isused[i] = 0;
        }
    }
}

int main() {

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