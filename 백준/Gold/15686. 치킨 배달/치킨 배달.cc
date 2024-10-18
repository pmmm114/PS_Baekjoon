#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int city[51][51];

int N, M;

int MIN = 1000000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    vector<pair<int, int>> chicken_position;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cin >> city[i][j];
            if(city[i][j] == 2) chicken_position.push_back({i,j});
        }
    }

    vector<int> chicken_combination(chicken_position.size(), 1);
    fill(chicken_combination.begin(), chicken_combination.begin() + M, 0);

    
    // 2가지를 고르는 치킨집 조합
    do {
        // 치킨집과 집의 거리를 계산
        vector<vector<int>> distance;
        
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=N;j++) {
                if(city[i][j] == 1) {
                    // 해당 집과 치킨집들 사이의 거리들 측정
                    vector<int> tmp;
                    for(int k=0;k<chicken_position.size();k++) {
                        tmp.push_back(
                            abs(i - chicken_position[k].first) +
                            abs(j - chicken_position[k].second)
                        );
                    }
                    distance.push_back(tmp);
                }
            }
        }

        int _dist = 0;
        for(int i=0;i<distance.size();i++) {
            int _min = 100000;
            for(int j=0;j<chicken_position.size();j++) {
                if(chicken_combination[j] == 1) continue;
                _min = min(_min, distance[i][j]);
            }
            _dist += _min;
        }
        MIN = min(MIN, _dist);

    } while(next_permutation(chicken_combination.begin(), chicken_combination.end()));

    cout << MIN;

    return 0;
}