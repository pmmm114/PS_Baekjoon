function solution(priorities, location) {
    var answer = 0;
    
    const _priorities = priorities.map((item, index) => [index, item]);
    
    let execute = []
    while(0 < _priorities.length) {
        let curr = _priorities.shift();
        
        if(_priorities.length <= 0) {
            execute.push(curr);
            break;
        }
        
        if(_priorities.findIndex(item => item[1] > curr[1]) !== -1) {
            _priorities.push(curr);
        } else {
            execute.push(curr);
        }
    }
    
    const index = execute.findIndex( item => item[0] === location);
    
    answer = index + 1;
    
    return answer;
}