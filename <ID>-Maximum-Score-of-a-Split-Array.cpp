/*
Problem: Maximum Score of a Split Array
Platform: LeetCode
Link: https://leetcode.com/problems/maximum-score-of-a-split
ID: 3788
Difficulty: Medium

Intuition:
I noticed that for each possible split, we need two things:
1. The sum of all elements before the split (prefix sum).
2. The smallest element after the split (suffix minimum).

My target is to pick the split where the prefix sum is as big as possible and the suffix minimum is as small as possible, 
because score = prefixSum - suffixMin.  

Approach:
1. Precompute the suffix minimums from the end of the array. This allows us to get suffixMin(i) in O(1) for any i.
2. Iterate from the start of the array:
   - Keep a running prefix sum.
   - At each index i, calculate score(i) = prefixSum - suffixMin(i).
   - Track the maximum score seen so far.
3. Return the maximum score at the end.

Complexity:
Time: O(n) — we pass through the array twice (once for suffixMin, once for prefixSum)
Space: O(n) — for storing suffix minimums

Code:
*/

class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();

        vector<long long> prefix(n);
        vector<int> suffixMin(n);

        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        suffixMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);
        }

        long long ans = LLONG_MIN;

        for (int i = 0; i < n - 1; i++) {
            long long score = prefix[i] - suffixMin[i + 1];
            ans = max(ans, score);
        }

        return ans;
    }
};
