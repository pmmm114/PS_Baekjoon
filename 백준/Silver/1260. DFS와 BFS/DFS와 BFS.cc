#include <iostream>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

// 1000 * 1000 Maximum
int graph_array[1001][1001];
int visit_check[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin.tie(0);

    int N, M, V;
    // 현재 정점, 이동할 정점
    stack<int> stack;
    queue<int> queue;

    cin >> N >> M >> V;


    int X, Y;
    // 간선 개수 만큼
    for(int i=0;i<M;i++) {
        cin >> X >> Y;
        // 그래프 관계 -> 2차원 배열
        graph_array[X][Y] = 1;
        graph_array[Y][X] = 1;
    }

    // DFS
    cout << V << ' ';
    stack.push(V);
    visit_check[V] = 1;
    
    while(!stack.empty()) {
        int cur = stack.top();
        bool is_pop = true;

        // 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문
        // i - 방문할 정점
        for(int i=1;i<=N;i++) {
            // 접근 가능한 정점일 경우
            if(graph_array[cur][i] == 1 && visit_check[i] != 1 && cur != i) {
                visit_check[i] = 1;
                stack.push(i);
                cout << i << " ";
                is_pop = false;
                break;
            }
        }

        if(is_pop) {
            stack.pop();
        }
    }
    cout << '\n';

    // 초기화
    for(int i=1;i<=N;i++) {
        visit_check[i] = 0;
    }

    // BFS
    queue.push(V);
    visit_check[V] = 1;
    while(!queue.empty()) {
        int cur = queue.front();queue.pop();
        cout << cur << ' ';

 
        // 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문
        // i - 방문할 정점
        for(int i=1;i<=N;i++) {
            // 접근 가능한 정점일 경우
            if(graph_array[cur][i] == 1 && visit_check[i] != 1 && cur != i) {
                visit_check[i] = 1;
                queue.push(i);
            }
        }
    }


    return 0;
}