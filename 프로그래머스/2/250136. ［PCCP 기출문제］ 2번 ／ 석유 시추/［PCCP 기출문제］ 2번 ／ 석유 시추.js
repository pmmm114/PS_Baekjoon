function solution(land) {
    // 세로길이 n, 가로길이 m
    // 가장 많은 석유를 뽑을 수 있는 시추관의 위치 찾기
    //  -   시추관은 열 하나를 관통
    
    //  POINT)
    //  1. 열 위에서 아래로 BFS를 진행하고 중복을 방지
    //  2. 모든 열을 진행하여 최대값을 가져오기
    
    // 아래 좌표 x, 오른쪽 좌표 y
    let max = 0;
    
    const rows = land.length;
    const cols = land[0]?.length || 0;  // 첫 행이 존재할 때만 열 길이를 가져옴
    
    let visited;
    const reset_visited = () => {
        visited = land.map((row, row_index) => row.map((col, col_index) => false));
    }
    const BFS = (x, y) => {
        const _queue = [];
        const dir = [{dx: 0, dy: 1}, {dx: 0, dy: -1}, {dx: 1, dy: 0}, {dx: -1, dy: 0}];
        let count = 1;
        const colSet = new Set([y]);
    
        
        _queue.push({x: x, y: y});
        visited[x][y] = true;
        while(_queue.length > 0) {
            let cur = _queue.shift();
            for(let i=0;i<dir.length;i++) {
                let nx = cur.x + dir[i].dx;
                let ny = cur.y + dir[i].dy;
            
                // 불가능한 지역
                if(nx >= rows || ny >= cols || nx < 0 || ny < 0) continue;
                // 방문했던 지역
                if(visited[nx][ny] === true) continue;
                // 기름이 아닌 곳, skip
                if(land[nx][ny] === 0) continue;
                
                visited[nx][ny] = true;
                _queue.push({x: nx, y: ny});
                count++;
                colSet.add(ny);
            }
        }
        
        return { count, colSet };
    }
    
    const max_col = Array(cols).fill(0);
    reset_visited();
    for(let i=0;i<rows;i++) {
        let _count = 0;
        for(let j=0;j<cols;j++) {
            if(land[i][j] === 0 || visited[i][j] === true) continue;
            let { count, colSet } = BFS(i, j);
            for (const col of colSet) {
                max_col[col] += count;
            }
        }
    }

    max = Math.max(...max_col);
    
    return max;
}