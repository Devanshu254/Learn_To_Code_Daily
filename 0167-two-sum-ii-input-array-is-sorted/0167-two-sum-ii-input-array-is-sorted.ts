function twoSum(numbers: number[], target: number): number[] {
    let n = numbers.length;
    let i = 0;
    let j = n-1;
    while(i<j) {
        if(numbers[i] + numbers[j] > target) {
            j--;
        }else if(numbers[i] + numbers[j] < target) {
            i++;
        }else {
            return [i+1,j+1];
        }
    }
    return [];
};