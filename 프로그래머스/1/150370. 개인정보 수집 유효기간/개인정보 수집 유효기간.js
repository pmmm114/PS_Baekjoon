function solution(today, terms, privacies) {
    var answer = [];
    
    const termsMap = new Map();
    // 약관 기간등록
    terms.forEach(item => {
        let term = item.split(" ");
        
        termsMap.set(term[0], term[1]*28);
    });
    
    const convertDateToDay = (date) => {
        const _date = date.split(".");
        
        const day = (Number(_date[0]) * (28 * 12)) + Number(_date[1] * 28) + Number(_date[2]);
        
        return day;
    }
    
    const result = privacies.map((privacy, index)=>{
        let _privacy = privacy.split(" ");
        let limit = convertDateToDay(_privacy[0]) + termsMap.get(_privacy[1]);
        
        // 파기
        if (convertDateToDay(today) >= limit ) return index+1;
    }).filter(item => item);
    
    answer = result;
    
    return answer;
}