class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total_drinks = numBottles;
        int empty_bottles = numBottles;
        while(empty_bottles >= numExchange) {
            int newFullbottles = empty_bottles/numExchange;
            total_drinks += newFullbottles;
            empty_bottles = newFullbottles + empty_bottles % numExchange;
        }
        return total_drinks;
    }
};