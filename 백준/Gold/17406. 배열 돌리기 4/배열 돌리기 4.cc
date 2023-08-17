#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct RotateInfo {
    int r, c, s;
};

vector<RotateInfo> rotate_vector;
int N, M, K;
int arr[51][51];

int calc_row() {
    int min = 0;
    for (int row = 0; row < N; row++) {
        int row_total = 0;
        for (int col = 0; col < M; col++) {
            row_total += arr[row][col];
        }
        if (row == 0 || row_total < min) min = row_total;
    }

    return min;
}

void rotate_arr(int r, int c, int s) {
    int temp_arr[51][51];
    memcpy(temp_arr, arr, sizeof(arr));

    for (int layer = 0; layer < s; layer++) {
        int start_row = r - s - 1 + layer;
        int start_col = c - s - 1 + layer;
        int end_row = r + s - 1 - layer;
        int end_col = c + s - 1 - layer;

        for (int i = start_col; i < end_col; i++) {
            arr[start_row][i + 1] = temp_arr[start_row][i];
        }

        for (int i = start_row; i < end_row; i++) {
            arr[i + 1][end_col] = temp_arr[i][end_col];
        }

        for (int i = end_col; i > start_col; i--) {
            arr[end_row][i - 1] = temp_arr[end_row][i];
        }

        for (int i = end_row; i > start_row; i--) {
            arr[i - 1][start_col] = temp_arr[i][start_col];
        }
    }
}

int main() {
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    for (int k = 0; k < K; k++) {
        int r, c, s;
        cin >> r >> c >> s;
        rotate_vector.push_back({r, c, s});
    }

    vector<int> order(K);
    for (int i = 0; i < K; i++) {
        order[i] = i;
    }

    int min_result = 0;  // 여기서 값을 설정하지 않고 아래에서 첫 번째 결과를 받아올 때 초기화합니다.
    bool first_result = true;
    do {
        int temp_arr[51][51];
        memcpy(temp_arr, arr, sizeof(arr));
        for (int i = 0; i < K; i++) {
            rotate_arr(rotate_vector[order[i]].r, rotate_vector[order[i]].c, rotate_vector[order[i]].s);
        }
        
        int current_result = calc_row();
        
        // 첫 번째 결과를 받아올 때 min_result를 초기화합니다.
        if (first_result) {
            min_result = current_result;
            first_result = false;
        } else {
            min_result = min(min_result, current_result);
        }

        memcpy(arr, temp_arr, sizeof(arr));
    } while (next_permutation(order.begin(), order.end()));

    cout << min_result << "\n";

    return 0;
}