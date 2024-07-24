class Solution {
    public String[] sortPeople(String[] names, int[] heights) {
        int n = names.length;
        Map<Integer, String> mapping = new HashMap<>();
        for(int i=0;i<n;i++) {
            mapping.put(heights[i], names[i]);
        }
        Arrays.sort(heights);
        String[] result = new String[heights.length];
        int index = 0;
        for(int i=heights.length-1;i>=0;i--) {
            result[index] = mapping.get(heights[i]);
            index++;
        }
        return result;
    }
}