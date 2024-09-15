class Solution {
    public boolean isPalindrome(String s) {

        int n = s.length();
        int i = 0, j = n - 1;

        while (i <= j) {

            while (i < n && !isAlphabetNum(s.charAt(i)))
                i++;

            while (j >= 0 && !isAlphabetNum(s.charAt(j)))
                j--;

            if (i > j)
                break;

            if (Character.toLowerCase(s.charAt(i)) != Character.toLowerCase(s.charAt(j)))
                return false;

            i++;
            j--;
        }

        return true;
    }

    private boolean isAlphabetNum(char c) {
        return (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9');
    }
}