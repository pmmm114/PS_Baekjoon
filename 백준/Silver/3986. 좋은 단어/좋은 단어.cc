// 제한시간 1초
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int N;
string word;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int cnt = 0;
    for(int i=0;i<N;i++) {
        stack<char> stack_01;
        cin >> word;

        for(char c : word) {
            if (!stack_01.empty() && stack_01.top() == c) stack_01.pop();
            else stack_01.push(c);
        }

        if(stack_01.empty()) cnt++;
    }

    cout << cnt << '\n';
}