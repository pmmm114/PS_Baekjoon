function solution(k, tangerine) {
    var answer = 0;
    
    const _map = new Map();
    
    //  경화는 수확한 귤 중 'k'개를 골라 상자 하나에 담아 판매
    //  귤의 크기가 일정하지 않아 보기에 좋지 않다고 생각한 경화는 귤을 크기별로 분류했을 때 서로 다른 종류의 수를 최소화
    //  Q. 크기가 서로 다른 종류의 수의 최솟값
    
    tangerine.forEach((item, index) => {
        _map.set(item, (_map.get(item) || 0) + 1);
    });
    
    const sorted = [..._map.entries()].sort((a, b) => b[1] - a[1]);
    
    let _k = k;
    for(let i=0;i<sorted.length;i++) {
        _k -= sorted[i][1];
        answer++;
        
        if(_k <= 0) break;
    }
    return answer;
}