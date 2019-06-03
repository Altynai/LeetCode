class Solution {
    public String gcdOfStrings(String str1, String str2) {
        if (str1.length() < str2.length()) {
            String tmp = str1;
            str1 = str2;
            str2 = tmp;
        }
        if (str2.equals(""))
            return str1;
        if (!str1.startsWith(str2))
            return "";
        do {
            str1 = str1.substring(str2.length());
        } while (str1.startsWith(str2));
        return gcdOfStrings(str1, str2);
    }
}
