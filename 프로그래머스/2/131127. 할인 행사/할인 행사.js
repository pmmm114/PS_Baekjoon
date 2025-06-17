function solution(want, number, discount) {
    var answer = 0;
    
    const wantMap = new Map();
    
    for(let i=0;i<want.length;i++) {
        wantMap.set(want[i], number[i]);
    }
    
    //  일정한 금액을 지불하면 10일 동안 회원 자격을 부여
    //  회원을 대상으로 매일 한 가지 제품을 할인하는 행사
    //      할인하는 제품은 하루에 하나씩만 구매
    
    //  Q. 회원등록시 정현이가 원하는 제품을 모두 할인 받을 수 있는 회원등록 날짜의 총 일수
    
    for(let i=0;i<=discount.length-10;i++) {
        //  10일 연속 체크
        let _wants = new Map(wantMap);
        
        for(let day=i;day<i+10;day++) {
            let _itemCount = _wants.get(discount[day]);
            if( !_itemCount || _itemCount <= 0) break;
            
            _wants.set(discount[day], _itemCount-1);
        }
        if( [..._wants].reduce((prev, curr) => prev + curr[1], 0) === 0 ) answer++;
    }
    return answer;
}