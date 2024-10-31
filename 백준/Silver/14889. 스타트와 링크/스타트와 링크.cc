#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int board[20][20];
int N;

int MIN = 2000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> board[i][j];
        }
    }

    vector<int> combination(N, 1);
    fill(combination.begin(), combination.begin() + N/2, 0);

    // for(int i =0;i<combination.size();i++) {
    //     cout << combination[i] << " ";
    // }
    // cout << '\n';

    // 20명에서 10명 뽑기
    vector<int> team_start;
    vector<int> team_link;
    int sum_team_start, sum_team_link;
    do{
        team_link.clear();
        team_start.clear();
        sum_team_start = 0;
        sum_team_link = 0;
        
        // 팀 선택
        for(int i=0;i<combination.size();i++) {
            if(combination[i] == 0) {
                team_start.push_back(i);
            } else {
                team_link.push_back(i);
            }
        }
        // 스타트팀 점수
        for(int i=0;i<team_start.size();i++) {
            for(int j=0;j<team_start.size();j++) {
                if(team_start[i] == team_start[j]) continue;
                // i번 사람과 j번 사람의 점수
                sum_team_start += board[team_start[i]][team_start[j]];
            }
        }
        
        // 링크팀 점수
        for(int i=0;i<team_link.size();i++) {
            for(int j=0;j<team_link.size();j++) {
                if(team_link[i] == team_link[j]) continue;
                // i번 사람과 j번 사람의 점수
                sum_team_link += board[team_link[i]][team_link[j]];
            }
        }

        MIN = min(MIN, abs(sum_team_link - sum_team_start));
    } while(next_permutation(combination.begin(), combination.end()));

    cout << MIN;

    return 0;
}