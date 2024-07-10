/**
 * @param {string[]} logs
 * @return {number}
 */
var minOperations = function(logs) {
    let level = 0;
    for(const log of logs) {
        if(log == "../") {
            if(level != 0) {
                level--;
            }
        }else if(log == "./") {
            continue;
        }else {
            level++;
        }
    }
    return level;
};