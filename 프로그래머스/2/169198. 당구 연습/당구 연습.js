function solution(m, n, startX, startY, balls) {
  const sx = startX, sy = startY;
  const res = [];

  for (const [tx, ty] of balls) {
    let best = Infinity;

    // 아래벽(y = 0)
    if (!(sx === tx && sy > ty)) {
      const dx = sx - tx;
      const dy = sy + ty;           // sy − (−ty)
      best = Math.min(best, dx * dx + dy * dy);
    }

    // 윗벽(y = n)
    if (!(sx === tx && sy < ty)) {
      const dx = sx - tx;
      const dy = sy - (2 * n - ty); // sy − (2n − ty)
      best = Math.min(best, dx * dx + dy * dy);
    }

    // 왼벽(x = 0)
    if (!(sy === ty && sx > tx)) {
      const dx = sx + tx;           // sx − (−tx)
      const dy = sy - ty;
      best = Math.min(best, dx * dx + dy * dy);
    }

    // 오른벽(x = m)
    if (!(sy === ty && sx < tx)) {
      const dx = sx - (2 * m - tx); // sx − (2m − tx)
      const dy = sy - ty;
      best = Math.min(best, dx * dx + dy * dy);
    }

    res.push(best);
  }
  return res;
}