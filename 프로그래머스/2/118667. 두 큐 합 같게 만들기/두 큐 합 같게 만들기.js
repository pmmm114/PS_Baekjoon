function solution(queue1, queue2) {
    const n = queue1.length;
    const totalArr = queue1.concat(queue2);
    
    let sum1 = queue1.reduce((a, b) => a + b, 0);
    let sum2 = queue2.reduce((a, b) => a + b, 0);
    const target = (sum1 + sum2) / 2;

    if ((sum1 + sum2) % 2 !== 0) return -1; // 홀수면 불가능

    let left = 0;
    let right = n;
    let currentSum = sum1;
    let count = 0;

    // 최대 반복 횟수 제한: 3 * n (양쪽 왔다갔다 최대치)
    const limit = n * 3;

    while (count <= limit) {
        if (currentSum === target) return count;
        else if (currentSum < target) {
            currentSum += totalArr[right];
            right++;
        } else {
            currentSum -= totalArr[left];
            left++;
        }
        count++;
    }

    return -1;
}
