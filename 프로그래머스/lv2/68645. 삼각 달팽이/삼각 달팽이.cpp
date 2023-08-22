#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<vector<int>> triangle(n, vector<int>(n, 0));
    vector<int> answer;
    int num = 1;
    int x = -1, y = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (i % 3 == 0) x++;
            else if (i % 3 == 1) y++;
            else if (i % 3 == 2) x--, y--;
            triangle[x][y] = num++;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            answer.push_back(triangle[i][j]);
        }
    }

    return answer;
}

// n4, n[3]=4 + (4-1) + (4-2), 3개
// n5, n[3]=5 + (5-1) + (5-2), 3개
// n6, n[3]=6 + (6-1) + (6-2), 3개

// n4, n[5] = 10 
// n5, n[5] = 13
// n6, n[5] = 16



// n[1]=1, n[2]=2
// n[n!+1] = n




// 1. n 만큼
// 2. n-1 만큼
// 3. n-2 만큼
