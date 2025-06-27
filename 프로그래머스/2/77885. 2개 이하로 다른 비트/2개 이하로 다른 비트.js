function solution(numbers) {
    const answer = [];

    for (let num of numbers) {
        num = BigInt(num);

        if (num % 2n === 0n) {
            // 짝수면 바로 다음 수가 답
            answer.push(num + 1n);
        } else {
            // 홀수면 비트 조작
            let bit = 1n;

            // 가장 오른쪽 0 찾기
            while (num & bit) {
                bit <<= 1n;
            }

            // 해당 0을 1로, 그 바로 오른쪽 비트를 0으로
            const result = num | bit;
            const modified = result & ~(bit >> 1n);

            answer.push(modified);
        }
    }

    return answer;
}
