#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string a, b;

int D[1001][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    int len_a = a.length();
    int len_b = b.length();

    for(int i=1;i<=len_a;i++) {
        for(int j=1;j<=len_b;j++) {
            // 마지막 문자가 같은 경우
            if(a[i-1] == b[j-1]) {
                D[i][j] = D[i-1][j-1] + 1;
            }
            // 마지막 문자가 다를 경우
            else {
                D[i][j] = max(D[i-1][j], D[i][j-1]);
            }
        }
    }

    cout << D[len_a][len_b];

    return 0;
}