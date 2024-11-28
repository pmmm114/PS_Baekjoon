#include <iostream>

using namespace std;

int N, M;
int NUM[2001];
int D[2001][2001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=1;i<=N;i++) {
        cin >> NUM[i];
    }

    // 초기값
    for (int i=1;i<=N;i++) {
        // 단일 수
        D[i][i] = 1;
        // 두칸짜리 팰린드롬
        if (NUM[i - 1] == NUM[i]) D[i - 1][i] = 1;
    }

    // 3개수 팰린드롬부터 확인
    for( int interval=2;interval<=N;interval++) {
        for(int i=1;i<=N - interval;i++) {
            int _S = i;
            int _E = i + interval;

            if(D[_S + 1][_E - 1] == 1 && NUM[_S] == NUM[_E]) D[_S][_E] = 1;
        }
    }

    cin >> M;
    int S, E;
    while(M--) {
        cin >> S >> E;

        cout << D[S][E] << '\n';
    }

    return 0;
}

/**
 * 
 * 테이블 정의
 * 1-N까지 팰린드롬 체크
 * s ~ e = 팰린드롬
 * s+1 ~ e-1 = 팰린드롬
 * 
 */