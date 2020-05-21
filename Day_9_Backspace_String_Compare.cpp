/* Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?  */


/* Approach - Traverse string from back */

// Time Complexity - O(m + n), where m is size of string S and n is size of string T
// Space Complexity - O(1)

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string sWithoutHash = "", tWithoutHash = "";
        int hashCount = 0;
        for (int i = S.size() - 1; i >=0 ;i--) {
            if (S[i] == '#') {
                hashCount++;
            }
            else {
                if (hashCount == 0) {
                    sWithoutHash = S[i] + sWithoutHash;
                }
                else {
                    hashCount--;
                }
            }
        }
        hashCount=0;
        for (int i = T.size() - 1;i >= 0; i--) {
            if (T[i] == '#') {
                hashCount++;
            }
            else {
                if (hashCount == 0) {
                    tWithoutHash = T[i] + tWithoutHash;
                }
                else {
                    hashCount--;
                }
            }
        }
        return sWithoutHash == tWithoutHash;
    }
};