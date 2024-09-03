class Solution {

    private int getSumOfDigit(int num) {

        int sum = 0;

        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }

    public int getLucky(String s, int k) {
        int sum = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            sum += getSumOfDigit(c - 'a' + 1);
        }

        while (--k > 0) {
            sum = getSumOfDigit(sum);
        }

        return sum;
    }
}