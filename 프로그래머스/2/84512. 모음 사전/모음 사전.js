function solution(word) {
    var answer = 0;
    
    //  1번째 자리: 5⁴ + 5³ + 5² + 5¹ + 1 = 781
    //  2번째 자리: 5³ + 5² + 5¹ + 1 = 156
    //  3번째 자리: 5² + 5¹ + 1 = 31
    //  4번째 자리: 5¹ + 1 = 6
    //  5번째 자리: 1
    
    const chars = ['A', 'E', 'I', 'O', 'U'];
    const weights = [781, 156, 31, 6, 1];

    for (let i = 0; i < word.length; i++) {
        const idx = chars.indexOf(word[i]);
        answer += idx * weights[i] + 1;
    }
    
    return answer;
}