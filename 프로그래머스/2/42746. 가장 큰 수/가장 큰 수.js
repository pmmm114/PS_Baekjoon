function solution(numbers) {
    var answer = '';
    
    const strs = numbers.map(String);
    
    strs.sort((a,b) => (b+a).localeCompare(a+b));
    
    if(strs[0] === "0") return "0";
    
    answer = strs.join("");
    
    return answer;
}