function solution(users, emoticons) {
    //  1. 이모티콘 플러스 서비스 가입자를 최대한 늘리는 것
    //  2. 이모티콘 판매액을 최대한 늘리는 것
    
    //  n명에게 m개 할인 판매
    //  할인율은 10%, 20%, 30%, 40% 중 하나로 설정
    
    //  기준을 따라 이모티콘을 사거나, 이모티콘 플러스 서비스에 가입
    //      1. 각 사용자들은 자신의 기준에 따라 일정 비율 이상 할인하는 이모티콘을 모두 구매합니다.
    //      2. 각 사용자들은 자신의 기준에 따라 이모티콘 구매 비용의 합이 일정 가격 이상이 된다면, 이모티콘 구매를 모두 취소하고 이모티콘 플러스 서비스에 가입합니다.
    
    //  Q.  행사 목적을 최대한으로 달성했을 때의 이모티콘 플러스 서비스 가입 수와 이모티콘 매출액을 1차원 정수 배열에 담아 return
    //      => 이모티콘 별 적정 할인율을 책정
    
    //  => dfs 백트래킹, 이모티콘 할인률을 모두 선택해보며 선정
    const discounts = [10, 20, 30, 40];
    //  구독자 수, 판매액
    let result = [0, 0];
    
    const evaluate = (selected) => {
        //  할인율 별 구독자 수와 판매자 수 계산
        let subscribers = 0;
        let revenue = 0;
        
        for(let userIdx=0;userIdx<users.length;userIdx++) {
            let limit = users[userIdx][0];
            let total = 0;
            for(let emoticonIdx=0;emoticonIdx<emoticons.length;emoticonIdx++) {
                // 구매하지 않는 경우
                if(limit > selected[emoticonIdx]) continue;
                total += emoticons[emoticonIdx] * (100 - selected[emoticonIdx]) / 100;
            }
            
            if(users[userIdx][1] <= total) subscribers++;
            else revenue += total;
        }
        
        if(subscribers > result[0] || (subscribers === result[0] && revenue > result[1]) ) {
            result[0] = subscribers;
            result[1] = revenue;
        }
    }
    
    const dfs = (idx, selected) => {
        if (idx === emoticons.length) {
          evaluate(selected);
          return;
        }

        for (let d of discounts) {
          selected.push(d);
          dfs(idx + 1, selected);
          selected.pop();
        }
    }
    
    
    
    dfs(0, []);
    
    return result;
}