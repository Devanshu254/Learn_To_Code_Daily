class Solution {
    public String reverseParentheses(String s) {
        Stack<Character> stack = new Stack<>();
        StringBuilder res = new StringBuilder();
        for(int i=0;i<s.length();i++) {
            char ch = s.charAt(i);
            if(ch == '(' || ch != ')') {
                stack.push(ch);
            }else {
                ArrayList<Character> list = new ArrayList<>();
                while(stack.peek() != '(' && !stack.isEmpty()) {
                    list.add(stack.pop());
                }
                stack.pop();
                for(char c: list) {
                    stack.push(c);
                }
            }
        }
        while(!stack.isEmpty()) {
            res.insert(0, stack.pop());
        }
        return res.toString();
    }
}