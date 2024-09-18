// 입력은 k는 100000개 이하, 시간제한 1초이기때문에 n^2 알고리즘은 불가능하다.
// 따라서 스택을 사용해야한다.
// 총 시간복잡도 O(k)

#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    stack<int> stack_01;
    // input은 1,000,000 이하의 자연수
    // 최종적으로 적어낸 수의 합은 2^31-1보다 작거나 같은 정수
    int k, input;
    int sum = 0;
    cin >> k;

    // k만큼 반복, 시간복잡도 O(k)
    for(int i=0;i<k;i++) {
        cin >> input;

        // 
        if(input == 0) stack_01.pop(); // 시간복잡도 1
        else stack_01.push(input); // 시간복잡도 1
    }

    // 스택에 있는 모든 수를 더함, 시간복잡도 O(k)
    while(!stack_01.empty()) {
        sum += stack_01.top(); // 시간복잡도 1
        stack_01.pop(); // 시간복잡도 1
    }

    cout << sum << '\n';
}