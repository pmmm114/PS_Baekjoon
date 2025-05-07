function solution(r1, r2) {
    var answer = 0;
    
    let r1_y;
    let r2_y;
    let count = 0;
    
    
    for(let i=1;i<=r2;i++) {
        r2_y = Math.sqrt(Math.pow(r2, 2)-Math.pow(i, 2));
        r1_y = Math.sqrt(Math.pow(r1, 2)-Math.pow(i, 2)) || 0;
        
        count += Math.floor(r2_y) - Math.ceil(r1_y) + 1;
    }
    
    answer = count * 4;
    
    return answer;
}