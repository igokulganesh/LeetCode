
class Solution {
    public String reverseWords(String s) {
        String strs[] = s.trim().split(" +");

        StringBuilder result = new StringBuilder();

        for (int i = strs.length - 1; i >= 0; i--) {
            result.append(strs[i]);
            if (i > 0)
                result.append(" ");
        }

        return result.toString();
    }
}