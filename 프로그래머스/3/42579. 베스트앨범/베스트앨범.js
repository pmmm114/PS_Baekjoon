function solution(genres, plays) {
    var answer = [];
    
    //  스트리밍 사이트에서 장르 별로 가장 많이 재생된 노래를 두 개씩 모아 베스트 앨범을 출시
    const totalMap = new Map();
    const songsMap = new Map();
    
    
    for(let index=0;index<genres.length;index++) {
        totalMap.set(genres[index], (totalMap.get(genres[index]) || 0) +  plays[index]);
        songsMap.set(genres[index],  [...songsMap.get(genres[index]) || [], [index, plays[index]]])
    }
    
    // 2) 장르 우선순위
    const sortedGenres = [...totalMap.entries()]
        .sort((a, b) => b[1] - a[1])       // 총 재생 수 내림차순
        .map(([g]) => g);
    
    for(const genre of sortedGenres) {
        let list = songsMap.get(genre).sort((a,b) => b[1] - a[1]);
        
        for(let index=0;index<Math.min(list.length, 2);index++) {
            answer.push(list[index][0]);
        }
    }
    
    return answer;
}