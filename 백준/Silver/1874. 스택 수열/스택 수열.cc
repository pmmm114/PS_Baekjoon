// 15:09
// 입력 n은 100,000 이하의 자연수, 시간제한은 2초이기 때문에 n^2 알고리즘은 불가능하다.

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    stack<int> stack_01;
    string ans;

    // 스택에 넣은 최대값
    int cnt = 1;
    // n까지의 수를 스택에 넣었다가 늘어놓기
    int n;

    cin >> n;

    for(int i=0;i<n;i++) {
        // 나열하려는 수
        int input_sequence;
        cin >> input_sequence;

        for(int j=cnt;j<=input_sequence;j++) {
            stack_01.push(cnt++);
            ans += "+\n";
        }

        // 스택에서 가져오려는 수와 스택의 맨 위의 수가 다르면 불가능
        if(stack_01.top() != input_sequence) {
            cout << "NO" << '\n';
            // 종료
            return 0;
        }

        stack_01.pop();
        ans += "-\n";
    }

    cout << ans << '\n';
}