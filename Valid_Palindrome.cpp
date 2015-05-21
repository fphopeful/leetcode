/*
 * Problem: 125	Valid Palindrome
 *
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 *
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 *
 * Note:
 * Have you consider that the string might be empty? This is a good question to ask during an interview.
 *
 * For the purpose of this problem, we define empty string as valid palindrome.
 */

//Solution
class Solution {
public:
    bool isPalindrome(string s) {
		int i = 0, j = s.length() - 1;
		//Scann from head and tail
		while (i <= j) {
			//char doesn't match conditions, then we skip
			if (!((s[i] >= 'a' && s[i] <= 'z') ||
				(s[i] >= 'A' && s[i] <= 'Z') ||
				(s[i] >= '0' && s[i] <= '9'))) {
				i++;
				continue;
			}
			if (!((s[j] >= 'a' && s[j] <= 'z') ||
				(s[j] >= 'A' && s[j] <= 'Z') ||
				(s[j] >= '0' && s[j] <= '9'))) {
				j--;
				continue;
			}

			//we consider uppercase and lowercase 
			//of the same letter is suitable
			if ((s[i] >= 'a' && s[i] <= 'z') && 
				(s[j] >= 'A' && s[j] <= 'Z')) {
				if (s[i] - s[j] != 'a' - 'A') {
					return false;
				} else {
					i++;
					j--;
				}
			} else if ((s[i] >= 'A' && s[i] <= 'Z') && 
				(s[j] >= 'a' && s[j] <= 'z')) {
				if (s[i] - s[j] != 'A' - 'a') {
					return false;
				} else {
					i++;
					j--;
				}
			} else if (s[i] != s[j]) {
				return false;
			} else {
				i++;
				j--;
			}
		}
		return true;
    }
};

/*
 * here is another solution, that better than mine:

#include <cctype> // needed for isalnum(), isupper() and tolower().

class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
        {
            while (i < j && !isalnum(s[i])) i++;
            while (i < j && !isalnum(s[j])) j--;

            if (tolower(s[i]) != tolower(s[j]))
                return false;
        }
        return true;
    }
};

 *
 * use the header 'cctype' to deal with the similar problem is efficient.
 * we had better learn to use the function below:
 * tolower()	toupper()	-- as the name suggests.
 * islower()	isupper()	-- as the name suggests.
 * isalnum()				-- if parameter is alphabet or number, return true; otherwise, return false.
 * isalpha()				-- if parameter is alphabet, return true; otherwise, return false.
 *
 */
