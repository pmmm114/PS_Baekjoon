#include <iostream>
#include <cmath>

using namespace std;

int cnt;

void Zshape(int N, int r, int c) {
    // CONDITION: BASE
    if(N == 0) {
        cout << cnt << '\n';
        return;
    }    
    int standard_cord = pow(2, N-1);
    int squareWidth = pow(standard_cord, 2);

    if( r < standard_cord && c < standard_cord) {
        // z첫번째 사분면
    } else if(standard_cord <= c && r < standard_cord) {
        // z두번쨰 사분면
        cnt += squareWidth;
    } else if(standard_cord <= r  && c < standard_cord ) {
        // z세번째 사분면
        cnt += squareWidth*2;
    } else if(standard_cord <= r && standard_cord <= c){
        // z네번째 사분면
        cnt += squareWidth*3;
    }
    Zshape(N-1, r%standard_cord, c%standard_cord);
}

// 5행 4열

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int N, r, c;

    // 1 <= N <= 15
    // 0 <= r, c <= 2^n
    cin >> N >> r >> c;


    // Z반복
    // 2^1 * 2^1 -> 0,0 / 1,0 / 0,1 / 1,1 -> 사분면 기준칸수 1칸
    // -> 행, 열을 체크
    // 2^2 * 2^2 -> 0,0 / 2,0 / 0,2 / 2,2 -> 사분면 기준칸수 2칸
    // -> 행, 열을 체크
    // 2^3 * 2^3 -> 0,0 / 4,0 / 0,4 / 4,4 -> 사분면 기준칸수 4칸
    // -> 행, 열을 체크
    // 2^k * 2^k -> 0,0 / 2^(k-1),0 / 0,2^(k-1) / 2^(k-1),2^(k-1) -> 사분면 기준칸수 2^(k-1)칸

    Zshape(N, r, c);

    return 0;
}