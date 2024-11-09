class Solution {
    public int compress(char[] chars) {
        int start = 0;
        int i = 0;

        while (i < chars.length) {
            char cur = chars[i];
            int count = 0;

            while (i < chars.length && chars[i] == cur) {
                i++;
                count++;
            }

            chars[start++] = cur;

            if (count > 1)
                start = updateNumber(chars, start, count);
        }
        return start;
    }

    private int updateNumber(char[] chars, int start, int num) {
        for (Character c : Integer.toString(num).toCharArray())
            chars[start++] = c;
        return start;
    }
}