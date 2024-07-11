/**
 * @param {string} s
 * @return {string}
 */
var reverseParentheses = function(s) {
    const stack = [];
    let res = '';
    for(const ch of s) {
        if(ch === '(' || ch !== ')') {
            stack.push(ch);
        }
        else {
            const list = [];
            while(stack.length > 0 && stack[stack.length-1] !== '(') {
                list.push(stack.pop());
            }
            stack.pop();
            for(const c of list) {
                stack.push(c);
            }
        }
    }
    while(stack.length > 0) {
        res = stack.pop() + res;
    }
    return res;
};