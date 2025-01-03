class Solution {
    public String addBinary(String a, String b) {
        StringBuilder sb = new StringBuilder();
        int i = a.length() - 1;
        int j = b.length() - 1;

        char[] arrA = a.toCharArray();
        char[] arrB = b.toCharArray();

        int carry = 0;

        while (i >= 0 || j >= 0) {
            int sum = carry;

            if (i >= 0)
                sum += arrA[i--] - '0';

            if (j >= 0)
                sum += arrB[j--] - '0';

            carry = sum > 1 ? 1 : 0;
            sb.append(sum % 2);
        }

        if (carry > 0)
            sb.append(carry);

        return sb.reverse().toString();
    }
}
