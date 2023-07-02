#include <iostream>

using namespace std;

// Max 8 / true, false값으로 배열 사용여부를 체크하며 백트래킹의 경우엔 초기화를 항상해주도록 함
int sequence_flag_array[9]; 
int sequence_array[9]; 
//  (1 ≤ M ≤ N ≤ 8)
int N, M;

void sequence(int cur_index) {
    // BASE CONDITION: 모든 수열이 선택되면 출력
    if(  cur_index == M+1 ) {
        for(int i=1;i<=M;i++) {
            cout << sequence_array[i] << " ";
        }
        cout << '\n';
        return;
    }


    for(int i=1;i<=N;i++) {
        // CONDITION: 사용가능한 수라면
        if(!sequence_flag_array[i]) {
            sequence_array[cur_index] = i;
            sequence_flag_array[i] = 1;
            // 다음 인덱스로 이동
            sequence(cur_index+1);
            // 모든 처리를 했으니, 상태를 초기화해줌
            sequence_flag_array[i] = 0;
        }
    }
    // Next Index에 대해 추적
}

// 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    sequence(1);

    return 0;
}