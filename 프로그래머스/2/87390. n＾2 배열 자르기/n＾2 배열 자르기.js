function solution(n, left, right) {
    const dist = [];
    for(let i=left;i<=right;i++) {
        dist.push(Math.max(i%n + 1, Math.floor(i/n) + 1));
    }
    
    return dist;
}