function solution(name, yearning, photo) {
    var answer = [];
    
    
    answer = photo.map((item, index) => {
        return item.map((_name, _nameIndex) => {
            let _index = name.findIndex((__name, __nameIndex) => __name === _name);
            if(_index !== -1) {
                return yearning[_index];
            } else {
                return 0;
            }
        }).reduce((prev, curr) => prev+curr, 0);
    });
        
    return answer;
}