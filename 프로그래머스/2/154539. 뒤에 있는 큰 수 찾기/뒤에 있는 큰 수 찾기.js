function solution(numbers) {
    const n = numbers.length;
      const answer = Array(n).fill(-1);
      const stack = [];                 // 값이 아닌 인덱스를 저장

    for(let i=n-1;i>=0;i--) {
        const curr = numbers[i];
        
        // 자신보다 작거나 같은 후보군은 skip
        while(stack.length > 0 && numbers[stack[stack.length-1]] <= curr) stack.pop();
        
        // 스택 top이 현재 수에서 가장 가까운 수
        if(stack.length > 0) answer[i] = numbers[stack[stack.length-1]];
            
        stack.push(i); // 현재 원소를 후보로 등록
    }
    
    return answer;
}