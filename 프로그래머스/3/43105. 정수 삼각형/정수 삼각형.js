function solution(triangle) {
  const n = triangle.length;
  const dp = [...triangle[0]];   // 첫 행 복사

  for (let i = 1; i < n; i++) {
    const row = triangle[i];
    // 뒤에서 앞으로 갱신해야 같은 행의 dp가 서로 덮어쓰지 않음
    for (let j = row.length - 1; j >= 0; j--) {
      const left  = j - 1 >= 0        ? dp[j - 1] : -Infinity;
      const right = j     < dp.length ? dp[j]     : -Infinity;
      row[j] += Math.max(left, right);
    }
    dp.splice(0, row.length, ...row); // dp 갱신
  }

  return Math.max(...dp);
}