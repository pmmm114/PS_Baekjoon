function solution(n, t, m, timetable) {
    const timeStringToNumber = (timeString) => {
        const [h, m] = timeString.split(":").map(Number);
        return h * 60 + m;
    };
    
    const timeNumberToString = (timeNumber) => {
        const h = String(Math.floor(timeNumber / 60)).padStart(2, '0');
        const m = String(timeNumber % 60).padStart(2, '0');
        return h+":"+m;
    };
    
    const crewTimes = timetable.map(timeStringToNumber);
    let high = timeStringToNumber("23:59");
    let low = 0;
    let answer = 0; // 초기화 중요

    while (high >= low) {
        let mid = Math.floor((high + low) / 2);
        let startTime = 540;
        let crewQueue = [...crewTimes, mid].sort((a, b) => a - b);

        for (let i = 0; i < n; i++) {
            let count = 0;
            
            while(count < m) {
                //  콘이 셔틀에 탈 수 있는가?
                if(crewQueue[0] <= startTime) {
                    crewQueue.shift();
                    count++;
                } else {
                    break;
                }
            }
            
            startTime += t;
        }
        
        if (crewQueue.filter(item => item === mid).length > 0) {
            //  탑승불가
            high = mid - 1;
        } else {
            answer = mid;
            low = mid + 1;
        }
    }
    
    return timeNumberToString(answer);
}
