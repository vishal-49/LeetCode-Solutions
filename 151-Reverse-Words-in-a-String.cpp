/*
Problem: Reverse Words in a String
Platform: LeetCode
Link: https://leetcode.com/problems/reverse-words-in-a-string/
ID: 151
Difficulty: Medium

Intuition:
Thought about it like this: if I reverse the entire string, the words automatically come in reverse order, 
but each word itself is backwards.
For example:
"the sky is blue" → "eulb si yks eht"
So all I need to do next is reverse each word individually, and everything falls into place.

Approach:
1. Reversed the whole string first. Now the words are in the right order, just with their letters reversed.
2. Went through the string and reversed each word to fix the letters.
3. While doing this, skipped any extra spaces — kept only one space between words and removed leading/trailing spaces.
4. At the end, got a clean string with all the words reversed and nicely formatted.

Complexity:
Time: O(N)
Space: O(1) extra (output string not counted)

Code:
*/
class Solution {
public:
    string a;

    string chk(string s, int start, int end) {
        if (start < 0) return a;

        while (start >= 0 && s[start] == ' ')
            start--;

        if (start < 0) return a;

        end = start;

        while (start >= 0 && s[start] != ' ')
            start--;

        a.append(s.substr(start + 1, end - start));
        a.push_back(' ');

        return chk(s, start - 1, start - 1);
    }

    string reverseWords(string s) {
        a.clear();
        int n = s.size();
        chk(s, n - 1, n - 1);

        if (!a.empty() && a.back() == ' ')
            a.pop_back();

        return a;
    }
};
