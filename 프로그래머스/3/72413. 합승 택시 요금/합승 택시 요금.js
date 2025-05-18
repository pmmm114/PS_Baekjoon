function solution(n, s, a, b, fares) {
    var answer = 0;
    
    
    const dist = Array.from({length: n}, () => Array(n).fill(Infinity));
    for(let i=0;i<n;i++) dist[i][i] = 0;
    
    //  간선간 가중치
    fares.forEach((item) => {
        dist[item[0]-1][item[1]-1] = dist[item[1]-1][item[0]-1] = item[2];
    });
    
    // 3. Floyd-Warshall: 모든 쌍 최단 거리 갱신
    for (let k = 0; k < n; k++) {
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < n; j++) {
                dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    //  모든 탑승 분기점을 테스트
    let min = Infinity;
    for(let k=0;k<n;k++) {
        //  1. s -> k분기점까지 합승 + k->b + k->a
        //      k를 모든 노드로 테스트
        min = Math.min(min, dist[s-1][k] + dist[k][a-1] + dist[k][b-1]);
    }
    
    answer = min;
    
    return answer;
}