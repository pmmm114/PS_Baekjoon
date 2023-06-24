#include <iostream>
#include <string>

using namespace std;

int main() {
    int points[5];
    int temp_point = 0;
    int max = 0;
    int idx = 0;

    for(int i = 0;i < 5;i++) {
        points[i] = 0;
        for(int j=0;j < 4;j++) {
            cin >> temp_point;
            points[i] += temp_point;
        }
        // 우승자 무조건 있음
        if( max < points[i] ) {
            max = points[i];
            idx = i;
        }
    }
    
    cout << idx+1 << " " << max << endl;

    return 0;
}