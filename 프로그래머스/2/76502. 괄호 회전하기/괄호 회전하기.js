function solution(s) {
    let answer = 0;

    const checker = (str) => {
        const stack = [];
        
        for (let char of str) {
            if (char === '(' || char === '{' || char === '[') {
                stack.push(char);
            } else {
                if (stack.length === 0) return; // 닫는 괄호인데 스택이 비어있으면 잘못됨
                
                const last = stack.pop();
                
                if (char === ')' && last !== '(') return;
                if (char === '}' && last !== '{') return;
                if (char === ']' && last !== '[') return;
            }
        }
        
        if (stack.length === 0) answer++; // 스택 비었으면 올바른 구조
    };

    for (let i = 0; i < s.length; i++) {
        const rotated = s.slice(i) + s.slice(0, i);
        checker(rotated);
    }

    return answer;
}
