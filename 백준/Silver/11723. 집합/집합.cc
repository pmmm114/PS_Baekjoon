#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int input;
    // 집합
    int array[20] = { 0, };
    // 연산방법
    string method;
    // 연산값
    int num;
    // check flag
    int flag;


    // 1 <= input <= 3,000,000 
    cin >> input;


    // input번 반복
    for(int i=0;i<input;i++) {
        cin >> method;
        // num을 입력 안받아도 되는 경우
        // NOTICE: all
        if(method == "all") {
            // 배열 순회
            for(int j=0;j<20;j++) {
                array[j] = 1;
            }
            continue;
        }

        // NOTICE: empty
        if(method == "empty") {
            // 배열 순회
            for(int j=0;j<20;j++) {
                array[j] = 0;
            }
            continue;
        }


        cin >> num;
        // num을 입력받아야하는 경우
        // NOTICE: Add
        if(method == "add") {
            // 연산값이 있다면
            if(array[num-1] == 1) continue;
            array[num-1] = 1;
        }

        // NOTICE: remove
        if(method == "remove") {
            // 연산값이 없다면
            if(array[num-1] == 0) continue;
            array[num-1] = 0;
        }

        // NOTICE: check
        if(method == "check") {
            flag = 0;
            if(array[num-1] == 1) {
                flag = 1;
            }
            cout << flag << "\n";
            continue;
        }

        // NOTICE: toggle
        if(method == "toggle") {
            if(array[num-1] == 0) {
                // 연산값 없다면
                array[num-1] = 1;
            } else {
                // 연산값 있으면 삭제
                array[num-1] = 0;
            }
            continue;
        }
    }


    return 0;
}