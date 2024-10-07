#include <iostream>

using namespace std;

int video[64][64];

int N;

int dx[4]={0, 0, 1, 1};
int dy[4]={0, 1, 0, 1};

void quad_tree(int start_x, int start_y, int curr_size) {
    if(curr_size == 1) {
        cout << video[start_x][start_y];
        return;
    }

    int start_value = video[start_x][start_y];
    bool is_same = true;
    for(int i=start_x;i<start_x+curr_size;i++) {
        if(is_same == false) break;
        for(int j=start_y;j<start_y+curr_size;j++) {
            if(start_value != video[i][j]) {
                is_same = false;
                break;
            }
        }
    }

    int next_size = (curr_size/2);
    if(is_same == true) {
        cout << start_value;
        return;
    } else {
        cout << "(";
        for(int dir=0;dir<4;dir++) {
            // 0,0 / 0,4 / 4,0 / 4,4
            quad_tree(start_x+(next_size*dx[dir]), start_y+(next_size*dy[dir]), next_size);
        }
        cout << ")";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    char c;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> c;
            video[i][j] = c - '0';

        }
    }

    quad_tree(0, 0, N);

   return 0; 
}