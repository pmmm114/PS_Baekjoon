function solution(scoville, K) {
  let answer = 0;

  /* ---------- 최소 힙 util ---------- */
  const heapPush = (heap, v) => {
    heap.push(v);                       // ➊ 맨 끝에 추가
    let i = heap.length - 1;
    while (i > 0) {                     // ➋ sift-up
      const p = (i - 1) >> 1;
      if (heap[p] <= heap[i]) break;
      [heap[p], heap[i]] = [heap[i], heap[p]];
      i = p;                            // **반드시 i 갱신**
    }
  };

  const heapPop = (heap) => {
    if (!heap.length) return undefined;
    if (heap.length === 1) return heap.pop();

    const min = heap[0];                // ➊ 루트 보관
    heap[0] = heap.pop();               // ➋ 끝 노드를 루트로
    let i = 0;
    const n = heap.length;
    while (true) {                      // ➌ sift-down
      const l = i * 2 + 1, r = l + 1;
      let s = i;
      if (l < n && heap[l] < heap[s]) s = l;
      if (r < n && heap[r] < heap[s]) s = r;
      if (s === i) break;
      [heap[i], heap[s]] = [heap[s], heap[i]];
      i = s;
    }
    return min;
  };
  /* ---------------------------------- */

  // 1. 초기 힙 구성
  const heap = [];
  for (const v of scoville) heapPush(heap, v);

  // 2. 섞기 시뮬레이션
  while (heap.length >= 2 && heap[0] < K) {
    const first  = heapPop(heap);       // 가장 작은
    const second = heapPop(heap);       // 두 번째로 작은
    heapPush(heap, first + second * 2);
    answer++;
  }

  // 3. 결과
  return heap.length && heap[0] >= K ? answer : -1;
}
