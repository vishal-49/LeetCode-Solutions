/*
Problem: Remove Outermost Parentheses
Platform: LeetCode
Link: https://leetcode.com/problems/remove-outermost-parentheses/
ID: 1021
Difficulty: Easy

Intuition:
A valid parentheses string can be broken into smaller "primitive" parts, where each part is a complete and 
independent set of parentheses. For every such primitive string, the first '(' and the last ')' are just the 
outer cover — they don't add any real structure inside. So the idea is: for every primitive block, 
keep everything except its outermost pair.

Instead of explicitly splitting into primitives, we can track how deep we are inside parentheses. This depth 
tells us whether a bracket is an outer one or an inner one.

Approach:
1. Traversing the string character by character.
2. Also maintain a counter `balance` that represents how deep we are inside parentheses.
3. When we see '(':
   - If `balance` is greater than 0, it means this '(' is not an outermost one, so we keep it.
   - Then increase `balance`.
4. When we see ')':
   - First decrease `balance`.
   - If `balance` is still greater than 0 after decreasing, this ')' is not an outermost one, so we keep it.
5. Collect all kept characters into the result string.
6. Return the result.

Complexity:
Time: O(N) — we scan the string once  
Space: O(N) — for the result string

Code:
*/

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int depth = 0;

        for (char c : s) {
            if (c == '(') {
                if (depth > 0) ans += c;  
                depth++;
            }
            else { 
                depth--;
                if (depth > 0) ans += c;   
            }
        }
        return ans;
    }
};
