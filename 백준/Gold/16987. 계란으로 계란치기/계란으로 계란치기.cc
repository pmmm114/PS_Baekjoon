#include <iostream>
#include <algorithm>

using namespace std;

int N;
int eggs[8][2];
int _max = 0;
int cnt = 0;

// k번째 계란으로 다른 계란을 깨기
void strike_egg( int k ) {
    // 가장오른쪽에 있는 계란
    if(k == N) {
        _max = max(_max, cnt);
        return;
    }

    if(eggs[k][0] <= 0 || cnt == N-1 ) {
        strike_egg(k+1);
        return;
    }

    // 깨는 행동
    for(int i=0;i<N;i++) {
        if (k == i) continue;
        if(eggs[i][0] <= 0) continue;

        // 계란 박치기, 내구도 조정
        eggs[k][0] -= eggs[i][1];
        eggs[i][0] -= eggs[k][1];
        // 손에 있는 계란이 깨진 경우
        if( eggs[k][0] <= 0 ) {
            cnt++;
        }
        // 때린 계란이 깨진 경우
        if( eggs[i][0] <= 0 ) {
            cnt++;
        }
        strike_egg(k+1);

        // 손에 있는 계란이 깨진 경우
        if( eggs[k][0] <= 0 ) {
            cnt--;
        }
        // 때린 계란이 깨진 경우
        if( eggs[i][0] <= 0 ) {
            cnt--;
        }
        // 계란 박치기, 내구도 복구
        eggs[k][0] += eggs[i][1];
        eggs[i][0] += eggs[k][1];
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int durability, weight;
    for(int i=0;i<N;i++) {
        cin >> durability >> weight;

        eggs[i][0] = durability;
        eggs[i][1] = weight;
    }

    strike_egg(0);

    cout << _max;

    return 0;
}