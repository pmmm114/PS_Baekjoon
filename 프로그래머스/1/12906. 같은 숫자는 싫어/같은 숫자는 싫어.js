function solution(arr)
{
    var answer = [];
    
    let stack = [arr[0]];
    for(let i=1;i<arr.length;i++) {
        if(stack[stack.length-1] !== arr[i]) stack.push(arr[i])
    }
    answer = stack;
    
    return answer;
}