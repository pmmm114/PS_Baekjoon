#include <iostream>

using namespace std;

int num[100001];
long long D[100001];
int N, M;
int i, j;


int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    
    for(int i=1;i<=N;i++) {
      cin >> num[i];
    }
    
    // 초기값 설정
    D[1] = num[1];
    for(int i=2;i<=N;i++) {
      D[i] = D[i-1] + num[i];
    }
    
    while(M--) {
      cin >> i >> j;
      
      cout << D[N] - D[i-1] - (D[N] - D[j]) << '\n';
    }
    
    return 0;
}