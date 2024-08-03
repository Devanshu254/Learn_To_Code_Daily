class Solution {
    public boolean canBeEqual(int[] target, int[] arr) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int n = target.length;
        for(int i=0;i<n;i++) {
            map.put(target[i], map.getOrDefault(target[i],0)+1);
        }
        for(int i=0;i<n;i++) {
            if(map.containsKey(arr[i])) {
                map.put(arr[i], map.get(arr[i]) - 1);
                if(map.get(arr[i]) == 0) {
                    map.remove(arr[i]);
                }
            }
        }
        if(!map.isEmpty()) {
            return false;
        }
        return true;
    }
}