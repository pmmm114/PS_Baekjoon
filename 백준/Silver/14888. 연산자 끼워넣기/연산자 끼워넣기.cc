#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int num[11];

int N;

int MAX=-1000000000;
int MIN=1000000000;

int cur;

// +, -, *, /
int operators[4];

void calc(char operator_char, int calc_num) {
    switch (operator_char)
    {
    case '+':
        cur += calc_num;
        break;
    case '-':
        cur -= calc_num;
        break;
    case '*':
        cur *= calc_num;
        break;
    case '/':
        cur /= calc_num;
        break;
    
    default:
        break;
    }
} 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int num_index = 0;num_index<N;num_index++) {
        cin >> num[num_index];
    }

    for(int operator_type = 0;operator_type<4;operator_type++) {
        cin >> operators[operator_type];
    }

    vector<char> operators_permutation;
    for(int operator_type = 0;operator_type<4;operator_type++) {
        char oper;
        if(operator_type == 0) oper = '+';
        else if(operator_type == 1) oper = '-';
        else if(operator_type == 2) oper = '*';
        else oper = '/';

        for(int i=0;i<operators[operator_type];i++) {
            operators_permutation.push_back(oper); 
        }
    }

    // 정렬된 상태에서 시작
    sort(operators_permutation.begin(), operators_permutation.end());

    do {
        cur = num[0];
        // 연산자 순회하여 계산
        for(int i=0;i<N-1;i++) {
            calc(operators_permutation[i], num[i+1]);
        }
        MAX = max(MAX, cur);
        MIN = min(MIN, cur);
    }
    while(next_permutation(operators_permutation.begin(), operators_permutation.end()));
    
    cout << MAX << '\n';
    cout << MIN << '\n';
    
    return 0;
}