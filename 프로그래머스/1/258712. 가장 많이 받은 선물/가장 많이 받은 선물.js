function solution(friends, gifts) {
  const n = friends.length;
  const idx = new Map();
  for (let i = 0; i < n; i++) {
    idx.set(friends[i], i);
  }

  // 1) A가 B에게 몇 번 선물 줬는지 카운트
  const give = Array.from({ length: n }, () => Array(n).fill(0));
  for (const info of gifts) {
    const [s, r] = info.split(" ");
    give[idx.get(s)][idx.get(r)]++;
  }

  // 2) 선물 지수 계산 (준 횟수 − 받은 횟수)
  const giftPoint = Array(n).fill(0);
  for (let i = 0; i < n; i++) {
    let p = 0;
    for (let j = 0; j < n; j++) {
      p += give[i][j] - give[j][i];
    }
    giftPoint[i] = p;
  }

  // 3) 다음 달 받을 선물 수
  const recvNext = Array(n).fill(0);
  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      const a2b = give[i][j];
      const b2a = give[j][i];

      if (a2b > b2a) {
        // i가 j보다 많이 줬으니 i가 받을 차례
        recvNext[i]++;
      } else if (a2b < b2a) {
        recvNext[j]++;
      } else {
        // 주고받은 수 동률 → 선물 지수 비교
        if (giftPoint[i] > giftPoint[j]) {
          recvNext[i]++;
        } else if (giftPoint[i] < giftPoint[j]) {
          recvNext[j]++;
        }
        // 같으면 아무도 주고받지 않음
      }
    }
  }

  return Math.max(...recvNext);
}
