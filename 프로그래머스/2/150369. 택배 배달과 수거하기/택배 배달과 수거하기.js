function solution(cap, n, deliveries, pickups) {
  let answer = 0;
  let d = n - 1, p = n - 1;

  while (d >= 0 || p >= 0) {
    // 아직 남은 가장 먼 집 찾기
    while (d >= 0 && deliveries[d] === 0) d--;
    while (p >= 0 && pickups[p]   === 0) p--;
    if (d < 0 && p < 0) break;           // 모두 끝

    const dest = Math.max(d, p);         // 이번 왕복 최외곽
    answer += (dest + 1) * 2;            // 왕복 거리 누적

    // ---------- 배달 ----------
    let load = cap;
    while (load > 0 && d >= 0) {
      if (deliveries[d] === 0) { d--; continue; }
      const sent = Math.min(deliveries[d], load);
      deliveries[d] -= sent;
      load -= sent;
      if (deliveries[d] === 0) d--;
    }

    // ---------- 수거 ----------
    load = cap;
    while (load > 0 && p >= 0) {
      if (pickups[p] === 0) { p--; continue; }
      const got = Math.min(pickups[p], load);
      pickups[p] -= got;
      load -= got;
      if (pickups[p] === 0) p--;
    }
  }
  return answer;
}
