function solution(order) {
    let answer = 0;

    const n = order.length;
    const zim = [];
    for (let i = n; i >= 1; i--) {
        zim.push(i);
    }

    const belt = [];
    let idx = 0;
    
    while (true) {
        let curr = order[idx];
        
        if(zim.length > 0 && zim[zim.length - 1] === curr) {
            zim.pop();
            idx++;
            answer++;
        } else if(belt.length > 0 && belt[belt.length-1] === curr) {
            belt.pop();
            idx++;
            answer++;
        } else if(zim.length > 0) {
            belt.push(zim.pop());
        } else {
            break;
        }
    }
    
    return answer;
}