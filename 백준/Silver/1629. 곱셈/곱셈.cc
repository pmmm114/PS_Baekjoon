#include <iostream>

using namespace std;

using ll = long long;

ll calc(ll a, ll b, ll m) {
    if(b == 1) return a % m;
    ll val = calc(a, b/2, m);
    val = val * val % m;
    // 지수가 짝수일 경우
    if(b % 2 == 0) return val;
    // 지수가 홀수일 경우
    return val * a % m;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll A, B, C;

    cin >> A >> B >> C;
    
    cout << calc(A, B, C) << '\n';

    return 0;
}