/* 
 * Problem 6:	ZigZag Conversion
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
 * (you may want to display this pattern in a fixed font for better legibility)
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 *
 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 *
 */

/* Analysis:
 * 1. We can divide 'zigzag matrix' to some blocks, as below:
 *		P		A		H		N
 *		A P		L S		I I		G
 *		Y		I		R
 *	  We divide the example to 4 blocks;
 * 2. We can calculate every char's block number, block size, and row number;
 * 3. So we can travel 'zigzag matrix' form first row to last row, then we get the result string;
 * 4. Tips:
 *		4.1. numRows == 1 || numRows >= len, are special cases. we should treat these diffrently;
 *		4.2. row is 0 or numRows - 1, there is only one char in one block in the row.
 */

//Solution
class Solution {
public:
    string convert(string s, int numRows) {
        string result = "";
        int i = 0, len = s.length();
        int blk_size = 2 * numRows - 2;
        char tmp[2];
        tmp[1] = '\0';
        if (numRows == 1 || numRows >= len)
            return s;
        for (i = 0; i < numRows; i++) {
            int j;
            for (j = i; j < len; j = j + blk_size) {
                int blk_offset = j % blk_size;
                int blk_num = j / blk_size;
                tmp[0] = s[j];
                result = result + tmp;
                if (i != 0 && i != numRows - 1) {
                    int k = 0;
                    k = (blk_num * blk_size) + (blk_size - blk_offset);
                    if (k < len) {
                        tmp[0] = s[k];
                        result = result + tmp;
                    }
                }
            }
        }
        return result;
    }
};

/*
 * Notice£º
 * tmp[2], not very good;
 * result.push_back(s[j]), better.
 */
