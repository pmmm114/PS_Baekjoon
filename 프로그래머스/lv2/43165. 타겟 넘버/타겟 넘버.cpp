#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer;

void DFS(vector<int> origin_vector, int cur_index, int target, int acc) {
    // BASE CONDITION: 종료조건
    if(cur_index == origin_vector.size()) {
        if(acc == target){
            answer++;
        }
        return;
    }
    
    // 백트리킹 X, 모든 케이스를 체크 -, +
    DFS(origin_vector, cur_index+1, target, acc-origin_vector[cur_index]);
    DFS(origin_vector, cur_index+1, target, acc+origin_vector[cur_index]);
}

int solution(vector<int> numbers, int target) {
    DFS(numbers, 0, target, 0);
    
    return answer;
}