#include <string>
#include <queue>
#include <utility>
#include <vector>
#include <math.h>
#include <cstring>
#include <iostream>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool BFS(vector<string> board,int x, int y){
    queue<pair<int,int>> Q;
    bool visited[5][5] = {false,};
    
    visited[x][y] = true;
    Q.push({x,y});
    while(!Q.empty()){
        int curX = Q.front().first;
        int curY = Q.front().second;
        Q.pop();
        for(int i=0; i<4; i++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            int d = abs(x-nx) + abs(y-ny);
            if(nx < 0 || ny < 0 || nx>=5 || ny >=5) continue;
            if(visited[nx][ny] || d > 2) continue;
            visited[nx][ny] = true;
            
            if(board[nx][ny] == 'X') continue; // 맨하탄 거리가 2 이하인 경우만 보는거니까 파티션 있으면 통과
            else if(board[nx][ny] == 'P') return false;
            else Q.push({nx,ny});
        }
    }
    return true;
}
int isCorrect(vector<string> board){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(board[i][j] == 'P'){
                if(!BFS(board,i,j)) return 0; // 거리두기 안지킴
            }
        }
    }
    return 1;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i=0; i<5; i++){
        answer.push_back(isCorrect(places[i]));
    }
    return answer;
}