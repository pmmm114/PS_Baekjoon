function solution(s){
    var answer = true;
    
    const stack = [];
    
    for(let i=0;i<s.length;i++) {
        if(s[i] === '(') stack.push(s[i]);
        else {
            if(!stack.pop()) {
                answer = false;
                break;    
            }
        }
    }
    
    if(stack.length > 0) answer = false;

    return answer;
}