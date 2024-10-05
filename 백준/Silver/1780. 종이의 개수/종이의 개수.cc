#include <iostream>

using namespace std;

int paper[2187][2187];

int N;

int paper_count[3];

// 시작좌표
void cutting(int start_x, int start_y, int curr_size) {
    // 사이즈가 1이면 무조건 체크
    if(curr_size == 1) {
        paper_count[paper[start_x][start_y]+1]++;
        return;
    } 

    // 종이에 적힌 값이 모두 같은 수 인지 확인
    int prev;
    bool is_same = true;
    prev = paper[start_x][start_y];

    for(int i=start_x;i<(start_x+curr_size);i++) {
        for(int j=start_y;j<(start_y+curr_size);j++) {
            if(prev != paper[i][j]) {
                is_same = false;
                break;
            }
        }   
    }


    if(is_same == true) {
        paper_count[prev+1] ++;
        return;
    } else {
        for(int i=start_x;i<start_x+curr_size;i+=(curr_size/3)) {
            for(int j=start_y;j<start_y+curr_size;j+=(curr_size/3)) {
                cutting(i, j, curr_size / 3);
            }
        }
    }
 }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> paper[i][j];
        }   
    }

    cutting(0, 0, N);

    for(int i=0;i<3;i++) {
        cout << paper_count[i] << '\n';
    }

    return 0;
}