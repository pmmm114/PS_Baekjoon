#include <iostream>

using namespace std;

int N;

int paper[128][128];
int paper_count[2];

void cutting(int start_x, int start_y, int paper_size) {
    // 잘라진 종이가 모두 하얀색 또는 모두 파란색으로 칠해져 있거나, 하나의 정사각형 칸이 되어 더 이상 자를 수 없을 때까지 반복
    if(paper_size == 1) {
        paper_count[paper[start_x][start_y]]++;
        return;
    }

    bool is_same = true;
    // 모두 같은 색으로 칠해젼지 확인
    // bfs를 활용해도될듯
    for(int i=start_x;i<(start_x + paper_size);i++) {
        if(is_same == false) break;
        for(int j=start_y;j<(start_y + paper_size);j++) {
            if(paper[start_x][start_y] != paper[i][j]) {
                is_same = false;
                break;
            }  
        }
    }

    if(is_same == true) {
        // 종이가 모두 같은 색일 경우
        paper_count[paper[start_x][start_y]]++;
    } else {
        // 종이가 모두 같은 색이 아닐 경우
        for(int i=start_x;i<=start_x+(paper_size/2);i+=(paper_size/2)) {
            for(int j=start_y;j<=start_y+(paper_size/2);j+=(paper_size/2)) {
                cutting(i, j, paper_size/2);
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

    for(int i=0;i<2;i++) {
        cout << paper_count[i] << '\n';
    }

    return 0;
}