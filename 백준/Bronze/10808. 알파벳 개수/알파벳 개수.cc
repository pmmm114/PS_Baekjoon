#include <iostream>
#include <string>

using namespace std;

int main() {
    // input
    string input_str;

    int startCode = 97;
    int array[26] = { 0 };

    // 문제 입력값
    cin >> input_str;

    // 해당되는 알파벳이 있을 경우, 출력
    for(int i=0;i<input_str.size();i++) {
        array[(int)input_str[i] - startCode] += 1;
    }

    for(int i=0;i < 26;i++) {
        cout << array[i] << " ";
    }
} 