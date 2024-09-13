import java.util.Arrays;

class Solution {
    public String longestCommonPrefix(String[] strs) {
        StringBuilder result = new StringBuilder();
        Arrays.sort(strs);

        String a = strs[0];
        String b = strs[strs.length - 1];
        int n = Math.min(a.length(), b.length());

        for (int i = 0; i < n; i++) {
            if (a.charAt(i) != b.charAt(i))
                break;
            result.append(a.charAt(i));
        }

        return result.toString();
    }
}