class Solution {
    public String reverseParentheses(String s) {
        Stack<Character> stack = new Stack<>();
        StringBuilder res = new StringBuilder();
        for(int i=0;i<s.length();i++) {
            char ch = s.charAt(i);
            // Opening bracket.
            if(ch == '(' || ch != ')') {
                stack.push(ch);
            }else {
                // Closing bracket.
                ArrayList<Character> list = new ArrayList<>();
                while(!stack.isEmpty() && stack.peek() != '(') {
                    list.add(stack.pop());
                }
                // Remove the opening bracket.
                stack.pop();
                for(char c: list) {
                    stack.push(c);
                }
            }
        }
        while(!stack.isEmpty()) {
            res.insert(0,stack.pop());
        }
        return res.toString();
    }
}