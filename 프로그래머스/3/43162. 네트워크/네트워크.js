function solution(n, computers) {
    var answer = 0;
    
    //  네트워크 구성
    const network = new Map();
    for(let i=0;i<computers.length;i++) {
        const node = [];
        for(let j=0;j<computers[i].length;j++) {
            if(computers[i][j] === 0 || i === j) continue;
            node.push(j);
        }
        network.set(i, node);
    }
    const visited = Array(computers.length).fill(false);
    
    
    const bfs = (node) => {
        const queue = [node];
        visited[node] = true;
        let head = 0;
        while(head < queue.length) {
            let curr = queue[head++];
            
            let next_node = network.get(curr);
            for(let i=0;i<next_node.length;i++) {
                if(visited[next_node[i]] === true) continue;
                queue.push(next_node[i]);
                visited[next_node[i]] = true;
            }
        }
    }
    
    for(let i=0;i<computers.length;i++) {
        if(visited[i] === true) continue;
        bfs(i);
        answer++;
    }
    
    return answer;
}