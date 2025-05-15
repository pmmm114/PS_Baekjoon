function solution(clothes) {
    var answer = 0;
    
    const clothesMap = new Map();
    
    clothes.forEach(item => {
        clothesMap.set(item[1], [...(clothesMap.get(item[1]) || []),item[0]]);
    });
    
    let count = 1;
    for(const [type, clothe] of clothesMap) {
        count *= (clothe.length+1);
    }
    
    //  조합 구하기
    //  부위별 옷 가지수 + 1
    //  모두 안입는 경우를 제외
    
    answer = count - 1;
    
    return answer;
}