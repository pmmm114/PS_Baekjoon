function solution(data, col, row_begin, row_end) {
    //  2. 정렬
    const sorted = data.sort((a,b) => {
        if(a[col-1] === b[col-1]) return b[0] - a[0];
        return a[col-1] - b[col-1]
    });
    
    const getSi = (idx) => {
        const S_idx = sorted[idx].reduce((prev, curr, index) => {
            prev += curr % (idx+1);
            
            return prev;
        }, 0);
        
        return S_idx;
    }
    
    let hash = 0;
    for(let i=row_begin-1;i<row_end;i++) {
        hash ^= getSi(i);
    }
    
    return hash;
}