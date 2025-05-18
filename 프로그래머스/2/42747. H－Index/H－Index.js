function solution(citations) {
    var answer = 0;
    
    //  발표한 논문 n편 중, h번 이상 인용된 논문이 h편 이상이고 나머지 논문이 h번 이하 인용되었다면 h의 최댓값이 이 과학자의 H-Index
    const sorted = citations.sort((a,b) => a-b);
    const n = citations.length;
    
    let low = 0;
    let high = n;
    
    while(high >= low) {
        let mid = Math.floor((high+low) / 2);
        
        let cnt = 0;
        for (let i = 0; i < n; i++) {
            if (sorted[i] >= mid) cnt++;
        }
        
        if(cnt >= mid) {
            answer = mid;
            low = mid+1;
        } else high = mid-1;
    }
    
    
    return answer;
}