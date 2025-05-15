function solution(info, edges) {
    var answer = 0;
    
    //  최대한 많은 양을 가져오기
    //      단, 양의 수보다 늑대의 수가 같거나 많아지면 양을 잡아먹음
    
    const tree =  Array.from({length: info.length}, () => []);
    
    for(let i=0;i<edges.length;i++) {
        tree[edges[i][0]].push(edges[i][1]);
    }
    
    let maxSheep = 0;
    const dfs = (sheep, wolf, arr) => {
        maxSheep = Math.max(maxSheep, sheep);
        
        for(let i=0;i<arr.length;i++)  {
            const next = arr[i];
            
            const ns = sheep + (info[next] === 0);        // 다음 양·늑대 수
            const nw = wolf  + (info[next] === 1);
            if (nw >= ns) continue;                       // 제약 위반 → 가지치기
            
            const nextCand = arr.slice();
            nextCand.splice(i, 1);                 // 선택 노드 제거
            nextCand.push(...tree[next]);          // 자식 노드 추가
        
            dfs(ns, nw, nextCand);
        }
    }
    
    dfs(1, 0, tree[0]);
    answer = maxSheep;
    
    return answer;
}