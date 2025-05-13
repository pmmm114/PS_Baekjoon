function solution(x, y, n) {
    var answer = 0;
    
    // 거리 겸 방문확인
    const dist = Array(y+1).fill(-1);
    
    const bfs = (value) => {
        const _queue = [];
        
        _queue.push({value, dist: 0});
         dist[x] = 0;
        for(let front=0;front<_queue.length;front++) {
            let _curr = _queue[front];
            
            if(_curr.value === y) {
                dist[y] = Math.min(dist[y], _curr.dist);
                break;
            }
            for(let nextValue of [_curr.value+n, _curr.value*2, _curr.value*3]) {
                if(nextValue > y || dist[nextValue] !== -1) continue;
                
                dist[nextValue] = _curr.dist + 1;
                _queue.push({value: nextValue, dist: _curr.dist + 1});
            }
        }
    }
        
    bfs(x);
    
    answer = dist[y];
    
    return answer;
}