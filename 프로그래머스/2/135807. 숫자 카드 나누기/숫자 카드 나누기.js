function solution(arrayA, arrayB) {
    //  최대공약수
    function gcd(a, b) {
      while (b !== 0) {
        [a, b] = [b, a % b];
      }
      return a;
    }
    
    function gcdArray(arr) {
      return arr.reduce((acc, cur) => gcd(acc, cur));
    }
    
    //  Q. 가장 큰 양의 정수 a의 값
    //      철수는 철수의 모든 카드의 공약수이면서 영희의 모든 카드의 공약수가 아닌 값 중 최대값
    
    let gcdA = gcdArray(arrayA);
    let gcdB = gcdArray(arrayB);
    
    let Aflag = true;
    for(let i=0;i<arrayA.length;i++) {
        if(arrayB[i] % gcdA === 0) {Aflag = false;break;}
    }
    
    let Bflag = true;
    for(let i=0;i<arrayB.length;i++) {
        if(arrayA[i] % gcdB === 0) {Bflag = false;break;}
    }
    
    let _max = 0;
    if(Aflag === true && Bflag === true) {
        max = Math.max(gcdA, gcdB);
    } else if(Aflag === true) {
        max = gcdA;
    } else if(Bflag === true) {
        max = gcdB;
    } else {
        max = 0;
    }
    
    return max;
}