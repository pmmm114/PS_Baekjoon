#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// 그리디
// STEP1. 이용중인 Room에 대한 정보를 Vector로 정리 ( 단, 최소 개수로 사용 )
// STEP2. 주어진 book_time 정렬
// STEP3. 시간은 모두 분으로 변환하여 비교에 용이하도록

vector<vector<int>> room;

vector<vector<int>> convertBookTimeToMinutes(vector<vector<string>>& book_time) {
    vector<vector<int>> tmp;
    
    for(auto& i : book_time) {
        vector<int> v_tmp;
        for(int j=0;j<i.size();j++) {
                
            istringstream ss(i[j]);
            string token;

            int hours, minutes;

            std::getline(ss, token, ':');
            hours = std::stoi(token);

            std::getline(ss, token, ':');
            minutes = std::stoi(token);
            
            v_tmp.push_back(hours * 60 + minutes);
        }
        
        tmp.push_back(v_tmp);
    }

    return tmp;
}

int solution(vector<vector<string>> book_time) {
    vector<vector<int>> book_minutes;
    
    // STEP3
    book_minutes = convertBookTimeToMinutes(book_time);
    
    // STEP2
    sort(book_minutes.begin(), book_minutes.end());
    
    // STEP1
    for(auto& i : book_minutes) {
        int flag = 0;
        
        for(auto& j : room) {
            // CONDITION: room 정보로 현재 방을 추가해야하는지 확인
            if(j[1] + 9 < i[0]) {
                // 객실에서 예약을 추가로 받을 경우, 예약의 endTime으로 정보를 변경
                j[1] = i[1];
                flag = 1;
                break;
            }
        }
        
        if ( flag == 0 ) {
            room.push_back(i);
        }
    }
    
    return room.size();
}