function solution(maps) {
    var answer = 0;
    
    // 레버까지 BFS
    // 레버에서 출구까지 BFS
    
    // 3차원 BFS [x,y,경유지방문여부]
    let start;
    for(let row=0;row<maps.length;row++) {
        let col = maps[row].indexOf("S");
        if(col !== -1) {
            start = {x: col, y: row};
            break;
        }
    }
    
    const bfs = (x,y) => {
        const col = maps[0].length;
        const row = maps.length;
        const dirs = [{x:1, y:0}, {x:-1, y:0}, {x:0, y:1}, {x:0, y:-1}];
        const visited = Array.from({length: row},
              () => Array.from({length: col},
              () => Array(2).fill(false)));
        const queue = [];
        
        queue.push({x, y, flag: 0, dist: 0});
        visited[y][x][0] = true;
        while(queue.length > 0) {
            let curr = queue.shift();
            if (maps[curr.y][curr.x] === 'E' && curr.flag === 1) {
                return curr.dist;
            }
            
            for(let dir=0;dir<dirs.length;dir++) {
                let nx = curr.x + dirs[dir].x;
                let ny = curr.y + dirs[dir].y;
                
                if(nx < 0 || ny < 0 || ny >= row || nx >= col) continue;
                if(maps[ny][nx] == "X") continue;
                let _flag = curr.flag;
                if(maps[ny][nx] === "L") _flag = 1;
                if(visited[ny][nx][_flag] === true) continue;
                
                queue.push({x: nx, y: ny, flag: _flag, dist: curr.dist+1});
                visited[ny][nx][_flag] = true;
            } 
        }
        
        return -1;
    }
    
    return bfs(start.x, start.y);
}