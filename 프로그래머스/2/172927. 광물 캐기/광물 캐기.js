function solution(picks, minerals) {
    var answer = 0;
    
    let minFatigue = Infinity;
    const calcFatigue = (pick, mineral) => {
        let _mineral = -1;
        switch(mineral) {
            case "diamond": 
                _mineral = 0;
                break;
            case "iron":
                _mineral = 1;
                break;
            case "stone":
                _mineral = 2;
                break;
            default:
        }
            
        const fatigue = [
            [1, 1, 1],
            [5, 1, 1],
            [25, 5, 1]
        ]
        
        return fatigue[pick][_mineral];
    }
    
    // pick은 0: diamond, 1: iron, 2: stone
    const mining = (idx, picksArray, fatigue) => {
        let _fatigue = fatigue;
        
        // 최소값을 넘길 경우
        if(_fatigue >= minFatigue) return;
        // 종료조건: 곡괭이가 없거나 광물이 없는 경우
        if(picksArray.reduce((prev, curr) => prev+curr, 0) === 0 || idx >= minerals.length) {
            minFatigue = Math.min(minFatigue, _fatigue);
            return;
        }
        
        for(let i=0;i<3;i++) {
            if(picksArray[i] <= 0) continue;
            
            let _picks = [...picksArray];
            _picks[i]--;
            
            let add = 0;
            for (let j = idx; j < idx + 5 && j < minerals.length; j++) {
                add += calcFatigue(i, minerals[j]);
            }
            mining(idx + 5, _picks, _fatigue + add);
            _picks[i]++;
        }
    }
    
    mining(0, picks, 0);
    
    answer = minFatigue;
    
    return answer;
}