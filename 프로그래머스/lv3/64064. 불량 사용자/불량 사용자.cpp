#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool checkStr(string a, string b){
    if(a.size() != b.size()) return false;
    
    for(int i=0; i<a.size(); i++){
        if(b[i] == '*') continue;
        if(a[i] != b[i]) return false;
    }
    
    return true;
}


int solution(vector<string> user_id, vector<string> banned_id) {
    set<vector<string> > s;
    sort(user_id.begin(), user_id.end());
    
    vector<int> v;
    for(int i=0; i<user_id.size(); i++){
        v.push_back(0);
    }
    for(int i=0; i<banned_id.size(); i++){
        v[i] += 1;
    }
    
    do {
        vector<string> tmp;
        for(int i=0; i<user_id.size(); i++){
            if(v[i] == 1){
                if(checkStr(user_id[i], banned_id[i])){
                    tmp.push_back(user_id[i]);
                }
            }
        }
        
        sort(tmp.begin(), tmp.end());
        
        if(tmp.size() == banned_id.size()){
            s.insert(tmp);
        }
        
    } while(next_permutation(user_id.begin(), user_id.end()));
    //생성된 순열을 순회하며 user_id, banned_id를 확인한다. 일치하면 tmp 배열에 추가한다.
	//정렬과 set을 통해 중복을 제거하고 길이가 조건에 맞으면 insert
    
    return s.size();
}