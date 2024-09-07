class Solution {

    /*
     * Approach 1: Brute Force
     * Time: O(n^2)
     * Space: O(1)
     */
    // Brute Force Approach
    private boolean canCompleteCircuit_Brute(int[] gas, int[] cost, int startIndex) {
        int n = gas.length;
        int tank = 0;
        int cur = startIndex;

        do {
            tank += gas[cur] - cost[cur];

            if (tank < 0)
                return false;

            cur = (cur + 1) % n;
        } while (startIndex != cur);

        return true;
    }

    public int canCompleteCircuit_Brute(int[] gas, int[] cost) {

        for (int i = 0; i < gas.length; i++) {
            if (canCompleteCircuit_Brute(gas, cost, i))
                return i;
        }

        return -1;
    }

    /*
     * Using Greedy
     * Time: O(n)
     * Space: O(1)
     */
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.length;
        int start = 0;
        int total_surplus = 0;
        int surplus = 0;

        for (int i = 0; i < n; i++) {
            total_surplus += gas[i] - cost[i];
            surplus += gas[i] - cost[i];

            if (surplus < 0) {
                surplus = 0;
                start = i + 1;
            }
        }

        return (total_surplus < 0 ? -1 : start);
    }

}
