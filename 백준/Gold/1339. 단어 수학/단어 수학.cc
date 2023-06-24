#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int main() {
    int N;
    vector<string> strs;

    int alphabet[26] = {0};
    

    cin >> N;

    string str;
    for(int i=0;i<N;i++) {
        cin >> str;

        strs.push_back(str);
    }

    /*
        고려해야할 점
        문자 길이가 가장 긴 것
    */

    for(int i=0;i<strs.size();i++) {
        for(int j=0;j<strs[i].length();j++) {
            // strs[i]- 'A" == 0 -> A일때
            int pos = (int) pow(10, (strs[i].length()-1)-j);
            alphabet[strs[i][j] - 'A'] += pos;

        }
    }

    sort(alphabet, alphabet+26, compare);

    int index = 9;
    int sum = 0;
    for(int i=0;i<26;i++) {
        sum += (index * alphabet[i]);
        index--;
        if(index < 0) break;
    }

    cout << sum << endl;

    return 0;
}