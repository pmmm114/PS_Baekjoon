function solution(nums) {
    var answer = 0;
    
    //  총 N 마리의 폰켓몬 중에서 N/2마리를 가져가도 좋다고 했습니다.
    //  최대한 많은 종류의 폰켓몬을 포함해서 N/2마리를 선택
    
    const map = new Map();
    
    for(const number of nums) {
        map.set(number, (map.get(number) || 0) + 1);
    }
    
    answer = Math.min(map.size, nums.length / 2);
    
    return answer;
}