class Solution {
    public String convertDateToBinary(String date) {
        String year = date.substring(0, 4);
        String month = date.substring(5, 7);
        String day = date.substring(8, 10);

        StringBuilder builder = new StringBuilder();
        builder.append(Integer.toBinaryString(Integer.parseInt(year)));
        builder.append("-");
        builder.append(Integer.toBinaryString(Integer.parseInt(month)));
        builder.append("-");
        builder.append(Integer.toBinaryString(Integer.parseInt(day)));

        return builder.toString();
    }
}

/*
 * yyyy-mm-dd
 * 0123456789
 */