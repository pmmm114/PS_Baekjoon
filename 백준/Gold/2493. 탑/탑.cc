// 제한시간 1.5초, 입력은 500,000 이하의 자연수, 


#include <iostream>
#include <stack>
#include <utility>

using namespace std;

#define X first
#define Y second

// 탑의 수
int N;
// 탑의 높이는 100,000,000 이하의 자연수
stack< pair<int,int> > towers;

// 자료구조 TIP.
// 스택
// - 최상위 요소를 제외한 나머지 요소의 인덱스와 값을 확인할 수 없다.
// - 인덱스를 확인하기 위해 스택에 튜플을 넣는다.

// 이 문제의 키 포인트는 수신받는 탑을 스택에 정리
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    towers.push(make_pair(100000001, 0));  // 첫 번째 타워를 스택에 넣는다

    for(int i=1;i<=N;i++) {
        int height;
        cin >> height;
        
        while(towers.top().X < height) {
            towers.pop();
        }

        // 현재 수신하고 있는 탑의 index를 출력
        cout << towers.top().Y << " ";

        // 임시 stack에 삽입
        towers.push(make_pair(height, i));
    }
}
