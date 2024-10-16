#include <iostream>

using namespace std;

int laptop[40][40];

int N, M, K;
int ans = 0;

int R, C;


// 90도 회전
void rotation(int arr[10][10]) {
    int tmp[10][10];

    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            tmp[j][R-1-i] = arr[i][j];
        }
    }

    for(int i=0;i<C;i++) {
        for(int j=0;j<R;j++) {
            arr[i][j] = tmp[i][j];
        }
    }

    swap(R, C);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    for(int i=0;i<K;i++) {
        int sticker[10][10]={0};

        cin >> R >> C;

        for(int row=0;row<R;row++) {
            for(int col=0;col<C;col++) {
                cin >> sticker[row][col];
            }
        }

        bool already_sticky = false;
        for(int rotate=0;rotate<4;rotate++) {
            // 랩탑 순회
            for(int i=0;i<=N-R;i++) {
                if(already_sticky == true) break;
                for(int j=0;j<=M-C;j++) {
                    // 랩탑에서 스티커가 안붙은 좌표에서 스티커 붙는지 확인
                    int is_cant_stick_position_in_laptop = false;
                    for(int sticker_x=0;sticker_x<R;sticker_x++) {
                        if(is_cant_stick_position_in_laptop) break;
                        for(int sticker_y=0;sticker_y<C;sticker_y++) {
                            if(laptop[i+sticker_x][j+sticker_y] == 1 && sticker[sticker_x][sticker_y] == 1) {
                                is_cant_stick_position_in_laptop=true;
                                break;
                            }
                        }
                    }

                    // 현재 붙일 수 있는 자리라면 붙이기
                    if(is_cant_stick_position_in_laptop == false) {
                        for(int sticker_x=0;sticker_x<R;sticker_x++) {
                            for(int sticker_y=0;sticker_y<C;sticker_y++) {
                                if(sticker[sticker_x][sticker_y] == 1) {
                                    laptop[i+sticker_x][j+sticker_y] = 1;
                                }
                            }
                        }
                        already_sticky = true;
                        break;
                    }
                }
            }

            if(already_sticky == true) break;
            rotation(sticker);
        }
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            ans += laptop[i][j];
        }
    }

    cout << ans;
    
    return 0;
}