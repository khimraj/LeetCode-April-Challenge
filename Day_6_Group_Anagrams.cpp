/* Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter. */


/* Approach - Use hash map */

// Time Complexity - O(m*n), where n is length of strs and m is max length of string in strs
// Space Complexity - O(n)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagramGroups;
        map<string,vector<string>> stringAnagram;
        for (int i = 0; i < strs.size(); i++) {
            int charCount[26]={0};
            for (int j = 0; j < strs[i].size(); j++) {
                charCount[strs[i][j] - 'a']++;
            }
            string key = "";
            for (int j = 0; j < 26; j++) {
                key += to_string(charCount[j]);
                key += '#';
            }
            stringAnagram[key].push_back(strs[i]);
        }
        for (auto itr = stringAnagram.begin(); itr != stringAnagram.end(); itr++) {
            anagramGroups.push_back(itr->second);
        }
        return anagramGroups;
    }
};