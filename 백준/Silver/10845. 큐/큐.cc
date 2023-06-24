#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int command_number;
    int array[10000] = { 0,};
    string method;
    int method_param;
    int head = 0;
    int tail = 0;

    cin >> command_number;

    for(int i=0;i<command_number;i++) {
        cin >> method;

        if(method == "size") {
            // CONDITION: 사이즈 체크
            cout << tail - head << '\n';
        } else if (method == "empty") {
            // CONDITION: 빈 큐
            if(tail == head) cout << 1 << '\n';
            else cout << 0 << '\n';
        } else if (method == "front") {
            // CONDITION: 가장 앞
            if(array[head] > 0) cout << array[head] << '\n';
            else cout << -1 << '\n';
        } else if (method == "back") {
            // CONDITION: 가장 뒤
            if(array[tail-1] > 0) cout << array[tail-1] << '\n';
            else cout << -1 << '\n';
        } else if (method == "push") {
            cin >> method_param;
            array[tail++] = method_param;
        } else if (method == "pop") {
            if(array[head] > 0) {
                cout << array[head] << '\n';
                array[head++] = 0;
            }
            else  {
                cout << -1 << '\n';
            }
        } 
    }


    return 0;
}