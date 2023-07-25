#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <iostream>
#include <map>
#include<cmath>

using namespace std;
unordered_map<string,int> um;
unordered_map<string,int> timeBoard;
int DAY_TIME = 1439;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    for(int i=0; i<records.size(); i++){
        stringstream ss(records[i]);
        string time, number, type;
        
        ss >> time >> number >> type;
        
        string T = time.substr(0,2);
        string M = time.substr(3,2);
        
        if(type == "OUT") {
        // 출차
            if(timeBoard.find(number) != timeBoard.end()) {
                timeBoard[number] += (stoi(T) * 60 + stoi(M)) - um[number];
            }  else {
                timeBoard[number] = (stoi(T) * 60 + stoi(M)) - um[number];
            }
            // 출차처리
            um.erase(number);
                    
        } else {
        // 입차
            um[number] = stoi(T) * 60 + stoi(M);
        }
    }
    
    
    for(auto elem : um){
        timeBoard[elem.first] += DAY_TIME - elem.second;
    }
    
    map<string, int> timeBoardSorted(timeBoard.begin(), timeBoard.end());

    for(auto elem : timeBoardSorted){
        //cout << elem.second << '\n';
        double sum = 0;
        if(elem.second <= fees[0]) sum = fees[1];
        else {
            double time = elem.second - fees[0];
            sum += fees[1];
            sum += ceil(time/fees[2]) * fees[3];
        }
        answer.push_back(sum);
    }
    
    return answer;
}