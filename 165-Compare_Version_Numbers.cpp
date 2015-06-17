/*
 * Problem 165:	Compare Version Numbers 
 *
 * Compare two version numbers version1 and version2.
 * If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
 *
 * You may assume that the version strings are non-empty and contain only digits and the . character.
 * The . character does not represent a decimal point and is used to separate number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level 
 * revision of the second first-level revision.
 *
 * Here is an example of version numbers ordering:
 *
 * 0.1 < 1.1 < 1.2 < 13.37 
 */

/* 
 * 注意理解题意，'.'这个字符可能出现很多次，后面不再跟数字就认为是".0"版本  
 */

//Solution
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.size(), len2 = version2.size();
        int i = 0, j = 0;
        while (i < len1 || j < len2) {
            int a = 0, b = 0;
            while (i < len1 && version1[i] != '.') {
                a *= 10;
                a += version1[i] - '0';
                i++;
            }
            i++;
            while (j < len2 && version2[j] != '.') {
                b *= 10;
                b += version2[j] - '0';
                j++;
            }
            j++;
            if (a > b)
                return 1;
            if (a < b)
                return -1;
        }
        return 0;
    }
};
