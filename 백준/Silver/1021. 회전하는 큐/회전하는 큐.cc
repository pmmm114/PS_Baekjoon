// 시간제한은 2초
#include <iostream>
#include <deque>

using namespace std;

deque<int> DQ;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // N = 덱 크기, M = 뽑아내려는 수의 개수, 전체 움직임 수
    int N, M, CNT;

    cin >> N >> M;

    // 덱 초기화
    for(int i=1;i<=N;i++) {
        DQ.push_back(i);
    }


    CNT = 0;
    int target;
    while(M--) {
        // 숫자별 움직임 수
        int moving_cnt = 0;
        cin >> target;

        // 타겟까지 INDEX 체크        
        while(DQ.front() != target) {
            // 앞쪽요소를 뒤로 넘김으로써 회전
            DQ.push_back(DQ.front());
            DQ.pop_front();
            moving_cnt++;
        }

        if(DQ.size() / 2 < moving_cnt) {
            moving_cnt = DQ.size() - moving_cnt;
        }

        CNT += moving_cnt;

        DQ.pop_front();
    }

    cout << CNT << '\n';

}