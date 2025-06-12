function solution(elements) {
    //  Q.  원형 수열의 연속 부분 수열 합으로 만들 수 있는 수의 개수를 return
    
    const _set = new Set();
    
    for(let i=1;i<=elements.length;i++) {
        
        for(let startIndex=0;startIndex<elements.length;startIndex++) {
            let sum = 0;
            for(let length=startIndex;length<startIndex+i;length++) {
                sum+=elements[length%elements.length]
            }
            _set.add(sum);
        }
    }
    
    return _set.size;
}