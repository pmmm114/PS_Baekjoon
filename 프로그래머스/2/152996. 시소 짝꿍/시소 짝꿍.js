function solution(weights) {
    var answer = 0;
    
    const map = new Map();
    const ratios = [
        [1, 1],
        [2, 3],
        [3, 2],
        [1, 2],
        [2, 1],
        [3, 4],
        [4, 3]
    ];
    
    for(let weight of weights) {
        for(let [r1, r2] of ratios) {
            const target = (weight * r1) / r2;
            if(map.has(target)) {
                answer += map.get(target);
            }
        }
        
        map.set(weight, (map.get(weight) || 0) + 1);
    }
    
    return answer;
}