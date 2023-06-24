#include <iostream>
#include <math.h> // min 함수랑 max 함수

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int room_number;
    int set[10] = {0,};
    int answer = 0;
    int idx = 0;
    cin >> room_number;

    
    while(room_number){
        set[room_number%10]++;
        room_number/=10;
    }

    // answer 최대값
    for(int i=0;i<10; i++){
        if(i==6 || i==9) continue;
        answer = max(set[i], answer); // max 조건에 맞을 때,
        // idx를 대입
        //if(answer == set[i]) idx = i;
    }

    answer = max(answer , (set[6] + set[9] + 1)/2);
    // // 최대값이 6이나 9일 경우
    // if(idx == 6 || idx == 9) {
    //     // 나눴을 떄
    //     if(((set[6] + set[9]) / 2) )
    // }
    
    cout << answer << '\n';


    return 0;
}