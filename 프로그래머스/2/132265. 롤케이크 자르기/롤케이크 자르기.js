function solution(topping) {
    const leftMap = new Map();
    const rightMap = new Map();
    const leftKinds = [];
    
    // 오른쪽에 먼저 전체 토핑 종류 카운트
    for (let t of topping) {
        rightMap.set(t, (rightMap.get(t) || 0) + 1);
    }
    
    let answer = 0;
    for (let i = 0; i < topping.length - 1; i++) {
        const t = topping[i];

        // 왼쪽으로 이동
        leftMap.set(t, (leftMap.get(t) || 0) + 1);

        // 오른쪽에서 제거
        rightMap.set(t, rightMap.get(t) - 1);
        if (rightMap.get(t) === 0) rightMap.delete(t);

        if (leftMap.size === rightMap.size) answer++;
    }
    
    return answer;
}