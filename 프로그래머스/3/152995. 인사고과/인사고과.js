function solution(scores) {
    const [manScore1, manScore2] = scores[0];
    const manTotal = manScore1 + manScore2;

    // 첫 번째 점수 내림차순, 두 번째 점수 오름차순 정렬
    scores.sort((a, b) => {
        if (b[0] !== a[0]) return b[0] - a[0];
        return a[1] - b[1];
    });

    const candidates = [];
    let maxSecond = -1;

    for (let [score1, score2] of scores) {
        // 두 점수가 모두 더 큰 사원이 있으면 해당 사원 탈락
        if (score2 < maxSecond) {
            // 인센티브 대상 제외
            continue;
        }
        maxSecond = Math.max(maxSecond, score2);
        candidates.push([score1, score2]);
    }

    // 완호가 인센티브 대상인지 확인
    const isManIncluded = candidates.some(
        ([s1, s2]) => s1 === manScore1 && s2 === manScore2
    );
    if (!isManIncluded) return -1;

    // 석차 계산 (두 점수 합 기준 내림차순)
    candidates.sort((a, b) => (b[0] + b[1]) - (a[0] + a[1]));

    let rank = 1;
    let sameCount = 0;
    let prevSum = null;

    for (let [s1, s2] of candidates) {
        const sum = s1 + s2;

        if (prevSum === null) {
            prevSum = sum;
        } else if (sum < prevSum) {
            rank += sameCount;
            prevSum = sum;
            sameCount = 0;
        }

        sameCount++;

        if (s1 === manScore1 && s2 === manScore2) {
            return rank;
        }
    }

    return -1; // 이론상 여기 도달 불가
}
