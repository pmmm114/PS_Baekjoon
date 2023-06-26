#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Limit  1,000,000
int NUMBER_ARRAY[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int N, M;

    cin >> M >> N;

    NUMBER_ARRAY[0] = 1;
    NUMBER_ARRAY[1] = 1;

    for(int i=2;i<=N;i++) {
        // 배열 값이 1이라면 skip
        if(NUMBER_ARRAY[i] == 1) continue;
        for(int j=2*i;j<=N;j+=i) {
            NUMBER_ARRAY[j] = 1;
        }
    }

    // Non-Zero Base
    for(int i=M;i<=N;i++) {
         if(NUMBER_ARRAY[i]==0) cout << i << '\n';
    }

    return 0;
}