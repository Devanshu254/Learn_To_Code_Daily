/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int binaryToDecimal(String s) {
        int base = 1;
        int dec = 0;
        int n = (int)s.length();
        for(int i=n-1;i>=0;i--) {
            if(s.charAt(i) == '1') {
                dec += base;
            }
            base *= 2;
        }
        return dec;
    }
    public int getDecimalValue(ListNode head) {
        ListNode curr = head;
        StringBuilder s = new StringBuilder();
        while(curr != null) {
            int data = curr.val;
            char x = (data==1) ? '1':'0';
            s.append(x);
            curr = curr.next;
        }
        int ans = binaryToDecimal(s.toString());
        return ans;
    }
}