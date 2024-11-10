#include <iostream>
#include <algorithm>

using namespace std;

int A[501][501], D[501][501];
int N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= i; ++j)
          cin >> A[i][j];
     
     D[1][1] = A[1][1];
    
    for(int i = 2; i <= N; ++i)
        for(int j = 1; j <= i; ++j)
          D[i][j] = max(D[i-1][j-1], D[i-1][j]) + A[i][j];
      cout << *max_element(D[N] + 1, D[N] + N + 1);

    return 0;
}