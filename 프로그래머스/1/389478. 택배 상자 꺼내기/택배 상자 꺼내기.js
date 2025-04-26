function solution(n, w, num) {
    var answer = 0;
    
    let max_row = Math.ceil(n / w);
    
    // 1, 3, 5층 왼쪽에서 오른쪽
    // 2, 4, 6층 오른쪽에서 왼쪽
    
    // 현재 row
    let num_row = Math.floor((num-1) / w);
    let num_col = getColOfNum(num_row, num-1, w);

    
    // let cur_num = getNum(num_row, num_col, w);
    // console.log(cur_num);
    
    // 특정 숫자부터 위로
    let upstair_num = 0;
    for(let i=num_row;i<max_row;i++) {
        upstair_num = getNum(i, num_col, w);
        if(upstair_num <= n) answer++;
    }
    
    return answer;
}

// 특정 row, col의 num을 구하기
function getNum(row, col, w) {
    let num;
    if(row % 2 === 0) {
        num = row * w + (col+1);
    } else {
        num = ((row+1) * w) - col;
    }
    
    return num;
}

// 특정 숫자의 col 구하기
function getColOfNum(row, num, w) {
    let col;
    let normal_index = num % w;
    if(row % 2 === 0) {
        // 짝수 row
        col = normal_index;
    } else {
        // 홀수 row
        col = (w-1) - normal_index;
    }
    
    return col;
}