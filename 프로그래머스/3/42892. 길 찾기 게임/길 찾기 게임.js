function solution(nodeinfo) {
    var answer = [];
    
    //  nodeinfo로 전위순회, 후위순회를 진행
    //  전위순회 우선순위 = 부모, 자식왼쪽, 자식오른쪽
    //  후위순회 우선순위 = 자식왼쪽, 자식오른쪽, 부모
    const nodes = nodeinfo.map(([x,y], idx) => ({x, y, idx: idx+1, left: null, right: null}));
    
    // y축 내림차순
    let sorted = nodes.sort((a,b) => {
        if(a.y === b.y) return a.x - b.x;
        return b.y - a.y;
    });
    
    // 트리 구성
    const root = nodes[0];
    for(let i=1;i<nodes.length;i++) {
        const node = nodes[i];
        let curr = root;
        
        while(true) {
            if(node.x < curr.x) {
                if(curr.left === null) {
                    curr.left = node;
                    break;
                }
                curr = curr.left;
            } else {
                if(curr.right === null) {
                    curr.right = node;
                    break;
                }
                curr = curr.right;
            }
        }
    }
    
    const _pre = [];
    const _post = [];
    const dfs = (node) => {
        if(!node) return;
        _pre.push(node.idx);
        dfs(node.left);
        dfs(node.right);
        _post.push(node.idx);
    }
    
    dfs(root);
    
    answer = [_pre, _post];
    
    return answer;
}