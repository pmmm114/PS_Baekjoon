function solution(n, roads, sources, destination) {
    var answer = [];
    
    //  지도 정보를 통해 최단시간에 부대로 복귀하기
    //      단, 적군의 방해로 인해 되돌아오는 경로가 없어져 복귀가 불가능한 부대원도 있을 수 있음

    const graph = Array.from({ length: n + 1 }, () => []);
    const dist = Array(n + 1).fill(-1); // -1: 방문 안함
    
    // 그래프 구성 (양방향)
    for (const [a, b] of roads) {
        graph[a].push(b);
        graph[b].push(a);
    }
    
    const queue = [destination];
    let head = 0;
    dist[destination] = 0;
    
    while(head < queue.length) {
        const curr = queue[head++];
        
        for (const neighbor of graph[curr]) {
          if (dist[neighbor] === -1) {
            dist[neighbor] = dist[curr] + 1;
            queue.push(neighbor);
          }
        }
    }
    
    
    answer = sources.map(src => dist[src]);
    return answer;
}