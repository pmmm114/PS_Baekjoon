#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    stack<char> stack_01;
    string input;
    int count;
    string flag;
    
    cin >> count;

    // 순서대로 들어온 '(' 개수와 ')'개수가 매칭된다면 항상 조건에 성립됨
    // Stack은 쌓아서 확인하는 용도
    for(int i=0;i<count;i++) {

        cin >> input;

        // stack 초기화
        while( !stack_01.empty() ) stack_01.pop();
        flag = "YES";

        for(int i=0;i<input.size();i++) {

            if( input[i] == '(' ) {
                // CONDITION: 문자열이 '(' 일 경우
                stack_01.push(input[i]);
                continue;
            } else {
                // CONDITION: 문자열이 ')' 일 경우

                // CONDITION: 현재 Stack이 비었을 경우, NO 출력 이후 break
                if( stack_01.empty() ) {
                    flag = "NO";
                    break;
                }
                // CONDITION: 현재 Stack 요소가 존재할 경우, '(' 하나 stack.pop
                stack_01.pop();

            }
        }

        if(!stack_01.empty()) {
            flag = "NO";
        }

        cout << flag << '\n';
    }    

    return 0;
}