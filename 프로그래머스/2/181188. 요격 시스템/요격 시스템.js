function solution(targets) {
    var answer = 0;
    
    let _targets = targets;
    //  targets: 폭격 미사일의 x좌표 범위 목록
    //  최소의 미사일로 요격
    //  2차원 공간
    //  A나라가 발사한 미사일은 X 축 직선, 구간 (s, e) / 0 ≤ s < e ≤ 100,000,000
    //  B나라는 y축에 수평으로 미사일을 발사하고 경로에 걸쳐있는 미사일을 요격
    //      단, s와 e에서 발사한 미사일은 (s,e)구간의 미사일로는 요격하지 못합니다.
    //  요격 미사일 수의 최솟값
    
    //  targets는 최대 500,000개
    
    const sort_targets = () => {
        _targets.sort((a, b) => {
            return a[1] - b[1];
        });
    }
    sort_targets();
    let end = -1;

    for (let [s, e] of _targets) {
        // 현재 미사일이 이전 요격 범위를 벗어났다면 새로운 미사일 발사
        if (s >= end) {
            answer++;
            end = e;  // 이 미사일의 끝에 요격 미사일 설치
        }
    }
    
    return answer;
}