#include <iostream>
#include <queue>

using namespace std;

queue<int> trucks;
int bridge[100] = {0};

int N, W, L;
int ans = 0;

int bridge_weight() {
    int weight = 0;
    for(int i=0;i<W;i++) {
        weight += bridge[i];
    }

    return weight;
}

// 다리 위의 차가 1칸씩 차 이동
void truck_move() {
    for(int i=W-1;i>0;i--) {
        bridge[i] = bridge[i-1];
    }
    // 마지막 차는 밖으로 아웃
    bridge[0] = 0;
}

// 다리 위에 트럭이 있는지 확인
bool is_bridge_empty() {
    for(int i=0; i<W; i++) {
        if(bridge[i] != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> W >> L;

    int truck;
    for(int i=0;i<N;i++) {
        cin >> truck;
        trucks.push(truck); 
    }

    while(!trucks.empty() || !is_bridge_empty()) {
        truck_move();

        if(!trucks.empty()) {
            int curr_weight_on_bridge = bridge_weight();

            // 최대하중 이하면 다리건너기
            if(curr_weight_on_bridge + trucks.front() <= L) {
                bridge[0] = trucks.front();trucks.pop();
            }
        }

        ans++;
    }

    cout << ans << '\n';

    return 0;
}