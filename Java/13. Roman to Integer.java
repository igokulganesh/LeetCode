class Solution {
    private int getRomanValue(char c) {
        return switch (c) {
            case 'I' -> 1;
            case 'V' -> 5;
            case 'X' -> 10;
            case 'L' -> 50;
            case 'C' -> 100;
            case 'D' -> 500;
            case 'M' -> 1000;
            default -> 0;
        };
    }

    public int romanToInt(String s) {
        int result = 0;
        int n = s.length();
        char c;
        for (int i = 0; i < n; i++) {
            c = s.charAt(i);
            if (c == 'I' && i < n - 1 && (s.charAt(i + 1) == 'V' || s.charAt(i + 1) == 'X'))
                result -= 1;
            else if (c == 'X' && i < n - 1 && (s.charAt(i + 1) == 'L' || s.charAt(i + 1) == 'C'))
                result -= 10;
            else if (c == 'C' && i < n - 1 && (s.charAt(i + 1) == 'D' || s.charAt(i + 1) == 'M'))
                result -= 1;
            else
                result += getRomanValue(c);
        }

        return result;
    }
}

/*
 * 
 * I 1
 * IV 4
 * IX 9
 * V 5
 * X 10
 * XL 40
 * XC 90
 * L 50
 * C 100
 * CD 400
 * CM 900
 * D 500
 * M 1000
 * 
 */