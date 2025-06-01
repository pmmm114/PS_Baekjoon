function solution(k, d) {
    var answer = 0;
    
    //  Q. 모든 좌표내부의 가능한 점 개수
    
    for(let i=0;i<=d;i+=k) {
        let low = 0;
        let high = d;
        let max = 0;
        
        while(high >= low) {
            const mid = Math.floor((high+low) / (2*k)) * k;
            
            if(Math.sqrt(i**2 + mid**2) > d) {
                high = mid - k;
            } else {
                max = mid;
                low = mid + k;
            }
        }
        
        answer += (Math.floor(max/k) + 1);
    }
    
    return answer;
}


