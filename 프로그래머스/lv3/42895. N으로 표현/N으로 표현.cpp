// N=5
// D[i] = i, N을 i번을 사용하는 수 집합 
// N은 1-9번 까지
// 최솟값이 8보다 작은 경우만 구하기

// D[1] = 5
// D[2] = 55, 5+5, 5-5, 5/5, 5*5
// D[3] = 555, 55+5, 55-5, 55/5, 55*5, (5+5)+5, (5+5)-5, (5+5)/5, (5+5)/5, (5+5)*5
// D[4] = 5555, 555+5

// D[1] = N을 이어붙인 수 집합
// D[2] = N을 이어붙인 수 집합 + D[1]과 D[1]의 사칙연산을 한 수 집합
// D[3] = N을 이어붙인 수 집합 + D[2]과 D[1]의 사칙연산을 한 수 집합
// D[4] = N을 이어붙인 수 집합 + D[3]과 D[1]의 사칙연산을 한 수 집합

// D[K] = N을 이어붙인 수 집합 + D[K-1]과 D[1]의 사칙연산을 한 수 집합

#include <string>
#include <vector>
#include <set>
using namespace std;

vector<set<int>> V(9, set<int>());

int solution(int N, int number) {
    int answer = -1;
    
    // D[1] 초기화
    V[1].insert(N);        
    
    // 사용횟수 8까지만
    for(int i = 1; i <=8; i++) {
        // D[i] 정의
        for(int j = 0; j < i; j++) {
            for(auto num1 : V[j]) {
                for(auto num2 : V[i - j]) {
                    V[i].insert(num1 + num2);
                    V[i].insert(num1 - num2);
                    V[i].insert(num1 * num2);
                    if(num2 != 0)
                        V[i].insert(num1 / num2);
                }
            }
        }
        
        // N을 이어붙인 수
        int concatNum = stoi(string(i, '0' + N));
        V[i].insert(concatNum);
        
        // number가 D[i]에 있는지 확인
        if(V[i].count(number) > 0) {
            answer = i;
            break;
        }
    }
    
    return answer;
}

