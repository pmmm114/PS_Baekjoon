function solution(players, callings) {
    
    var answer = [];
    
    // 미리 rank → name 역-매핑도 하나 만들어 둡니다.
    const rankToName = new Map(players.map((name, idx) => [idx, name]));
    const _players = new Map(players.map((name, idx) => [name, idx])); // name → rank

    // current: 호출된 선수의 현 순위, target: 추월 후 순위(= current-1)
    const swap = (current, target) => {
      // 두 선수 이름을 먼저 얻는다.
      const curName    = rankToName.get(current);
      const targetName = rankToName.get(target);

      // rank → name 맵 갱신
      rankToName.set(current,  targetName);
      rankToName.set(target,   curName);

      // name → rank 맵 갱신
      _players.set(curName,    target);
      _players.set(targetName, current);
    };
    
    for(let i=0;i<callings.length;i++) {
        // 호명된 선수의 현재 등수
        let _index = _players.get(callings[i]);
        // 추월 후 등수
        let _target = _index - 1;
        swap(_index, _target);
    }
    
    answer = [...rankToName.values()];
    
    return answer;
}