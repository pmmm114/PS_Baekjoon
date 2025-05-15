function solution(phone_book) {
    const set = new Set(phone_book);
    
    for(const num of set) {
        let prefix = "";
        for(const ch of num) {
            prefix += ch;
            if(prefix === num) break;
            if(set.has(prefix)) return false;
        }
    }
    
    return true;
}