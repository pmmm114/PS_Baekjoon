#include <iostream>
#include <algorithm>

int arr[100001];
int comp_arr[100001];
int st, en;

using namespace std;

int binary_search(int target) {
    int mid;

    // st, en이 역전되기전까지 탐색
    while(st <= en) {
        mid = (st+en)/2;
        if(
            target > arr[mid]
        ) {
            st = mid + 1;
        } else if (
            target < arr[mid]
        ) {
            en = mid - 1;
        } else {
            return 1;
        }
    }
    // target이 없을 경우
    return 0;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, tmp;

    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> tmp;
        arr[i] = tmp;
    }
    

    cin >> M;
    for(int i=0;i<M;i++) {
        cin >> tmp;
        comp_arr[i] = tmp;
    }

    // 정렬
    sort(arr, arr + N);


    for(int i=0;i<M;i++) {
        st = 0;en = N-1;
        cout << binary_search(comp_arr[i]) << '\n';
    }

    return 0;
}