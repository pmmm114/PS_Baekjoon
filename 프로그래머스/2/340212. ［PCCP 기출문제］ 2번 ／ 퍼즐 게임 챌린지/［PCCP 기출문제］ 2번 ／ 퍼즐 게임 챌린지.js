function solution(diffs, times, limit) {
    const getTotalTime = (level) => {
        let _time = 0n;
        let prev_time = 0n;

        for (let i = 0; i < diffs.length; i++) {
            let time_cur = BigInt(times[i]);
            let diff = BigInt(diffs[i]);
            let _level = BigInt(level);

            if (diff <= _level) {
                _time += time_cur;
            } else {
                let mistakes = diff - _level;
                _time += (time_cur + prev_time) * mistakes + time_cur;
            }
            prev_time = time_cur;
        }
        return _time;
    }
    
    let start = 1n;
    let max_diff = 0;
    for (let i = 0; i < diffs.length; i++) {
      if (diffs[i] > max_diff) {
        max_diff = diffs[i];
      }
    }
    let end = BigInt(max_diff);
    let answer = end;
    let limitBig = BigInt(limit);

    while (start <= end) {
        let mid = (start + end) / 2n;
        mid = mid - (mid % 1n); // BigInt의 floor

        if (getTotalTime(mid) <= limitBig) {
            answer = mid;
            end = mid - 1n;
        } else {
            start = mid + 1n;
        }
    }
    
    return Number(answer);
}
