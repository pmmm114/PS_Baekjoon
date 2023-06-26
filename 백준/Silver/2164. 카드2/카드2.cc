#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    queue<int> queue;



    int N;

    cin >> N;

    for(int i=0;i<N;i++) {
        queue.push(i+1);
    }

    
    while(queue.size() > 1) {
        // 제일 위 제거
        queue.pop();

        // 제일 위 요소 가져오기
        queue.push(queue.front());

        queue.pop();
    }

    cout << queue.front() << '\n';
    
    return 0;
}