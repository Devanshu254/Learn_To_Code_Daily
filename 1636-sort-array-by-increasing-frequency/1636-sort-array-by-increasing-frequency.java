class Solution {
    public int[] frequencySort(int[] nums) {
        int n = nums.length;
        HashMap<Integer, Integer> freq = new HashMap<>();
        for(int num: nums) {
            freq.put(num, freq.getOrDefault(num,0)+1);
        }
        // We can not apply comparator sorting over int. We need to convert it into Integer. For that sake we are creating a new temp array.
        Integer temp[] = new Integer[n];
        for(int i=0;i<n;i++) {
            temp[i] = nums[i];
        }
        // Custom sorting.
        Arrays.sort(temp, new Comparator<Integer>() {
            public int compare(Integer a, Integer b) {
                if(freq.get(a) == freq.get(b)) {
                    return b-a; // Decreasing order.
                }
                // Else return increasing order of frequency. If values are not same.
                return freq.get(a) - freq.get(b);
            }
        });
        for(int i=0;i<n;i++) {
            nums[i] = temp[i];
        }
        return nums;
    }
}