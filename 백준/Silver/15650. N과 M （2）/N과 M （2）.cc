#include <iostream>

using namespace std;

int sequence[10];
int isused[10];

int N, M;

// k = 숫자의 자리
void back_tracking(int k) {
    // 종료조건
    if( k == M ) {
        for(int i=0;i<M;i++) {
            cout << sequence[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int st = 1;
    if(k!=0) st=sequence[k-1]+1;
    for(int i=st;i<=N;i++) {
        // 현재 수열에서 사용하지 않은 수 라면
        if(isused[i] != 1) {
            // 수열에 넣기
            sequence[k] = i;
            // 사용 플래그
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

    back_tracking(0);
    return 0;
}