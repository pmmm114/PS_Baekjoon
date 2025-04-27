function solution(storage, requests) {
    var answer = 0;
    
    let array_container = [];
    array_container = storage.map(row => [...row.split('')]);
    // 문자열이 단수이면 지게차로 출고가능한 컨테이너를 출고
    // 문자열이 복수이면 크레인으로 해당되는 모든 컨테이너 출고
    // RESULT) 모든 요청을 순서대로 처리한 후 남은 컨테이너 수
    
    // a좌표에서 외부로 나갈 수 있는 길을 탐색, bfs
    const can_out = (x, y) => {
        const queue = [];
        let visited = [];
        visited = Array.from({ length: array_container.length }, () => Array(array_container[0].length).fill(false));
        const dir = [{x: 1,y: 0},{x: -1,y: 0},{x: 0,y: 1},{x: 0, y: -1}];
        
        let cur;
        
        // 첫좌표 삽입
        queue.push({x: x, y: y});
        while(queue.length > 0) {
            cur = queue.shift();
            for(let i=0;i<dir.length;i++) {
                // 이동할 좌표
                let nx = cur.x + dir[i].x;
                let ny = cur.y + dir[i].y;
                
                // 외부로 연결되는 경우
                if (nx < 0 || ny < 0 || ny >= visited.length || nx >= visited[0].length) {
                    return true; // 외부 연결 성공
                }
                
                // 중복체크
                if(visited[ny][nx]) continue;
                
                // 컨테이너가 있을 경우 skip
                if(array_container[ny][nx] !== null) continue;
                
                queue.push({x: nx, y: ny});
                visited[ny][nx] = true;
            }
        }
            
        return false;
    }
    
    const find_container = (container_name) => {
        const positions = []
        array_container.forEach((row_item, row_index)=> {
            row_item.forEach((col_item, col_index) => {
                if(container_name.includes(col_item)) positions.push({x: col_index, y: row_index});
            })
        })
            
        return positions;
    }
    
    let command;
    while(requests.length > 0) {
        command = requests.shift();
        
        if(command.length > 1) {
            // 크레인
            find_container(command).forEach(container_position => {
                array_container[container_position.y][container_position.x] = null;
            })
        } else {
            // 지게차
            const can_out_position = find_container(command).filter(container_position => {
                return can_out(container_position.x, container_position.y);
            })
            
            can_out_position.forEach(item => {
                array_container[item.y][item.x] = null;
            })
        }
    }
    
    array_container.forEach((row, rowIndex) => {
        row.forEach((col, colIndex) => {
            if(array_container[rowIndex][colIndex] !== null) answer++;
        })
    })
    
    return answer;
}

