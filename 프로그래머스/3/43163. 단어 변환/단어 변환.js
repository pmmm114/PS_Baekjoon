function solution(begin, target, words) {
    var answer = 0;
    
    //  begin -> target
    
    //  1. 한 번에 한 개의 알파벳만
    //  2. words에 있는 단어로만 변환
    
    //  최소 몇단계?
    //  DFS
    if(words.includes(target) === false) return 0;
    
    const compare = (str1, str2) =>  {
      let diffCount = 0;
      for (let i = 0; i < str1.length; i++) {
        if (str1[i] !== str2[i]) {
          diffCount++;
        }
      }
      return diffCount;
    }
    
    let min = Infinity;
    const visited = Array.from({length:words.length}, () => false);
    const dfs = (word, step, state) => {
        if(word === target) {
            min = Math.min(min, step);
            return;
        }
        
        for(let i=0;i<state.length;i++) {
            if(state[i] === true) continue;
            if(compare(word, words[i]) > 1) continue;
            
            const _visited = [...state];
            _visited[i] = true;
            dfs(words[i], step+1, _visited);
            _visited[i] = false;
        }
    }
    
    dfs(begin, 0, visited);
    
    return min;
}