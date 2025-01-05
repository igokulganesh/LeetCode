class Solution {

    /*
     * Brute Force Method (Time Limit Exceeded)
     */
    public String shiftingLetters_1(String s, int[][] shifts) {
        char[] c = s.toCharArray();

        for (int[] shift : shifts) {
            int direction = shift[2] == 1 ? 1 : -1;

            for (int i = shift[0]; i <= shift[1]; i++) {
                c[i] = (char) ('a' + (c[i] - 'a' + direction + 26) % 26);
            }
        }

        return new String(c);
    }

    public String shiftingLetters(String s, int[][] shifts) {
        int n = s.length();
        int[] prefix = new int[n + 1];

        // Process each shift operation
        for (int[] shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2] == 1 ? 1 : -1;

            prefix[start] += direction;
            if (end + 1 < n)
                prefix[end + 1] -= direction;
        }

        // Apply the shifts to the string
        int curShift = 0;
        for (int i = 0; i < n; i++) {
            curShift += prefix[i];
            prefix[i] = curShift;
        }

        char[] result = new char[n];
        for (int i = 0; i < n; i++) {
            int shift = (prefix[i] % 26 + 26) % 26;
            result[i] = (char) ('a' + (s.charAt(i) - 'a' + shift) % 26);
        }

        return new String(result);
    }

}