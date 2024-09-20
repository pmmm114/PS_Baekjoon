// 제한시간 1초

#include <iostream>
#include <string>
#include <sstream>
#include <deque>

using namespace std;

// 테이스케이스 수
int T;
// 실행할 함수
string P;
// 배열의 길이
int n;
// 실행할 함수
// 배열
deque<int> DQ;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    // 테스트케이스
    for(int i=0;i<T;i++) {
        DQ.clear();

        // False 이면 정방향, True 이면 역방향
        bool is_reverse = false;
        bool is_error = false;
        string input_array;
        // 함수입력
        cin >> P;
        // input_array 길이 입력
        cin >> n;
        // input_array 입력
        cin >> input_array;

        string num;
        stringstream ss(input_array.substr(1, input_array.size() - 2)); // '['와 ']' 제거

        // 배열 길이 이상으로 버리는 함수를 수행할 수 없음
        int D_cnt = 0;
        for(char delete_function : P) {
            if(delete_function == 'D') D_cnt++;
        }

        if(D_cnt > n) {
            is_error = true;
        }
        
        // 덱에 배열 삽입
        while (getline(ss, num, ',')) {
            if (!num.empty()) {
                int value = stoi(num);
                if (value >= 1 && value <= 100) {  // 1이상 100이하의 자연수만 덱에 추가
                    DQ.push_back(value);
                }
            }
        }

        // 함수 수행
        int R_cnt = 0;
        for(char function : P) {
            if(function == 'R') is_reverse = !is_reverse;
            else if(function == 'D') {
                if(DQ.empty()) {
                    is_error = true;
                    break;
                }

                if(is_reverse) {
                    DQ.pop_back();
                } else {
                    DQ.pop_front();
                }
            }

        }


        // 출력
        if (is_error) {
            cout << "error" << '\n';
        } else {
            cout << '[';
            while(!DQ.empty()) {
                if(is_reverse) {
                    cout << DQ.back();
                    DQ.pop_back();
                } else {
                    cout << DQ.front();
                    DQ.pop_front();
                }

                if(!DQ.empty()) cout << ',';
            }
            cout << ']' << '\n';
        }
        
    }
}