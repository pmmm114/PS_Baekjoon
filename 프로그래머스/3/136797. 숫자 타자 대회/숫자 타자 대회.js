function solution(numbers) {
  const dist = Array.from({ length: 10 }, () => Array(10).fill(Infinity));

  // 숫자 자판 좌표 맵핑
  const pos = {
    1: [0, 0],
    2: [0, 1],
    3: [0, 2],
    4: [1, 0],
    5: [1, 1],
    6: [1, 2],
    7: [2, 0],
    8: [2, 1],
    9: [2, 2],
    0: [3, 1],
  };

  // 자기 자신: 제자리 누르기 (비용 1)
  for (let i = 0; i < 10; i++) {
    dist[i][i] = 1;
  }

  // 직접 연결된 간선 설정 (상하좌우: 2, 대각선: 3)
  for (let i = 0; i < 10; i++) {
    for (let j = 0; j < 10; j++) {
      if (i === j) continue;

      const [x1, y1] = pos[i];
      const [x2, y2] = pos[j];
      const dx = Math.abs(x1 - x2);
      const dy = Math.abs(y1 - y2);

      if (dx + dy === 1) {
        dist[i][j] = 2; // 상하좌우
      } else if (dx === 1 && dy === 1) {
        dist[i][j] = 3; // 대각선
      }
    }
  }
  // Floyd-Warshall: 간접 경로 최단거리 갱신
  for (let k = 0; k < 10; k++) {
    for (let i = 0; i < 10; i++) {
      for (let j = 0; j < 10; j++) {
        dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  const N = numbers.length;
  const dp = Array.from({ length: N + 1 }, () =>
    Array.from({ length: 10 }, () => Array(10).fill(Infinity)),
  );

  dp[0][4][6] = 0; // 초기 위치: 왼손 4, 오른손 6

  for (let i = 0; i < N; i++) {
    const target = parseInt(numbers[i]);

    for (let l = 0; l < 10; l++) {
      for (let r = 0; r < 10; r++) {
        const cur = dp[i][l][r];
        if (cur === Infinity) continue;

        // 해당 숫자 위에 손가락이 있다면 고정
        if (target === l) {
          dp[i + 1][target][r] = Math.min(
            dp[i + 1][target][r],
            cur + dist[l][target],
          );
        } else if (target === r) {
          dp[i + 1][l][target] = Math.min(
            dp[i + 1][l][target],
            cur + dist[r][target],
          );
        } else {
          // 두 경우 모두 고려
          dp[i + 1][target][r] = Math.min(
            dp[i + 1][target][r],
            cur + dist[l][target],
          );
          dp[i + 1][l][target] = Math.min(
            dp[i + 1][l][target],
            cur + dist[r][target],
          );
        }
      }
    }
  }

  // 마지막 상태 중 최소값 반환
  let result = Infinity;
  for (let l = 0; l < 10; l++) {
    for (let r = 0; r < 10; r++) {
      result = Math.min(result, dp[N][l][r]);
    }
  }

  return result;
}
