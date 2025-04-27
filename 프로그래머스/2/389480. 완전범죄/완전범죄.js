var answer = 9999999;
var visited;

function solution(info, n, m) {
    visited = Array.from({ length: info.length + 1 }, () =>
        Array.from({ length: n }, () => Array(m).fill(false))
    );
    
    dfs(info, n, m, 0, 0, 0);
    
    return answer === 9999999 ? -1 : answer; // 추가: 답이 없으면 -1 반환
}

function dfs(info, n, m, idx, aSum, bSum) {
    if (aSum >= n || bSum >= m) return;
    if (idx === info.length) {
        answer = Math.min(answer, aSum);
        return;
    }
    
    if (visited[idx][aSum][bSum]) return;
    visited[idx][aSum][bSum] = true; // 여기도 수정: 대입은 = 하나만!

    // A가 훔치기
    dfs(info, n, m, idx + 1, aSum + info[idx][0], bSum);
    
    // B가 훔치기
    dfs(info, n, m, idx + 1, aSum, bSum + info[idx][1]);
}
