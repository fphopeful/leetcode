/*
 * Problem 205:	Isomorphic Strings 
 *
 * Given two strings s and t, determine if they are isomorphic.
 *
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 *
 * All occurrences of a character must be replaced with another character while preserving the order of characters. 
 * No two characters may map to the same character but a character may map to itself.
 *
 * For example,
 * Given "egg", "add", return true.
 *
 * Given "foo", "bar", return false.
 *
 * Given "paper", "title", return true.
 *
 * Note:
 * You may assume both s and t have the same length.
 */

/* 
 * Analysis:
 * 1. ascii has total 256 chars;
 * 2. '\0' is the end marker of string;
 * 3. "No two characters may map to the same character" means 
      "if there is a => b in string s, there is b => a in string t". 
 */

//Solution
class Solution {
public:
    bool isIsomorphic(string s, string t) {
		short s_map[256] = {0}, t_map[256] = {0};
		int i = 0, len = s.length();
		//Traver form 0 to len -1
		for (i = 0; i < len; i++) {
			//map or check
			if (s_map[s[i]] == 0) {
				s_map[s[i]] = t[i];
			} else {
				if (s_map[s[i]] != t[i])
					return false;
			}
			// check: if one map to many or not 
			if (t_map[t[i]] == 0) {
				t_map[t[i]] = s[i];
			} else {
				if (t_map[t[i]] !=s[i])
					return false;
			}
		}
		return true;
    }
};