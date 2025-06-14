function solution(cards) {
    const visited = Array(cards.length).fill(false);
    const cycleSizes = [];

    for (let i = 0; i < cards.length; i++) {
        if (visited[i]) continue;

        let size = 0;
        let current = i;

        while (!visited[current]) {
            visited[current] = true;
            current = cards[current] - 1;
            size++;
        }

        cycleSizes.push(size);
    }

    cycleSizes.sort((a, b) => b - a);

    if (cycleSizes.length < 2) return 0;
    return cycleSizes[0] * cycleSizes[1];
}