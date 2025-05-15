function solution(n, edge) {
    var answer = 0;
    
    const tree = Array.from({length: n+1}, () => []);

    edge.forEach((item) => {
        tree[item[0]].push(item[1]);
        tree[item[1]].push(item[0]);
    })
    
    console.log(tree);
    
    // 최단거리
    const bfs = (node) => {
        const _queue = [];
        const dist = Array(n+1).fill(-1);
        let head=0;
        
        _queue.push(node);
        dist[node] = 0;
        while(head < _queue.length) {
            let curr = _queue[head++];
            for(let i=0;i<tree[curr].length;i++) {
                let next = tree[curr][i];
                if(dist[next] !== -1) continue;
                dist[next] = dist[curr] + 1;
                _queue.push(next);
            }
        }
        
        return dist;
    }
    
    const nodeDisrArray = bfs(1);
    
    answer = nodeDisrArray.filter(item => item === Math.max(...nodeDisrArray)).length;
    
    return answer;
}