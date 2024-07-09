class Solution {
    public double averageWaitingTime(int[][] customers) {
        int idleTime = 1;
        long total_waiting_time = 0;
        for(int customer[] : customers) {
            if(idleTime <= customer[0]) {
                idleTime = customer[0] + customer[1];
            }else {
                idleTime = idleTime + customer[1];
            }
            total_waiting_time += (idleTime - customer[0]);
        }
        double average =  (total_waiting_time)/(double)customers.length;
        return average;
    }
}