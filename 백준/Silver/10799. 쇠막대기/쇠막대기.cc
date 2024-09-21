// 제한시간 1초
#include <iostream>
#include <stack>
#include <string>


using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string sticks;
    cin >> sticks;

    stack<char> stack_01;

    int ans = 0;
    char prev = ' '; // 이전 문자를 저장할 변수
    for(char c : sticks) {
        if (c == '(') {
            stack_01.push(c);
        } else {
            stack_01.pop();
            if (prev == '(') {
                // 레이저로 절단
                ans += stack_01.size();
            } else {
                // 쇠막대기의 끝
                ans += 1;
            }
        }
        prev = c; // 현재 문자를 이전 문자로 저장
    }

    cout << ans << '\n';
    return 0;
}