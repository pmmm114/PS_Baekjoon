#include <iostream>

using namespace std;

int N, M;
int sequence[9];
int isused[10001];
int can_num[10001];

void back_tracking(int k) {
    if( k == M ) {
        for(int i=0;i<M;i++) {
            cout << sequence[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int st = 1;
    if(k != 0) {
        st = sequence[k - 1];
    }
    for(int i=st;i<=10001;i++) {
        if(can_num[i] == 0) continue;
        if(isused[i] == 0) {
            sequence[k] = i;
            isused[i] = 1;
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
        can_num[num]=1;
    }

    back_tracking(0);
    return 0;
}