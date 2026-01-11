/*
Problem: Spiral Order Matrix
Platform: LeetCode
Link: https://leetcode.com/problems/spiral-matrix/
ID: 54
Difficulty: Medium

Intuition:
I thought of the matrix like layers of an onion. If we start from the outermost layer and move inward, 
we can follow a spiral pattern. At each layer, we move right across the top, then down the right side, 
then left across the bottom, and finally up the left side. Repeat this until all elements are covered.

Approach:
1. Keep track of the boundaries: top, bottom, left, and right(so initialised 4 pointers with these names).
2. While the boundaries are valid (top <= bottom and left <= right):
   - Move across the top row from left to right, then move the top boundary down.
   - Move down the right column from top to bottom, then move the right boundary left.
   - If the top boundary hasn’t passed the bottom, move across the bottom row from right to left, then move the bottom boundary up.
   - If the left boundary hasn’t passed the right, move up the left column from bottom to top, then move the left boundary right.
3. Add elements to the result vector as we go.  
4. Keep repeating until the whole matrix is traversed in a spiral order.

Complexity:
Time: O(m * n) — each element is visited exactly once
Space: O(1) extra (output vector is mandatory, not counted)

Code:
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0 , bottom = m-1;
        int left = 0 , right = n-1;
        vector<int>ans;
        while(top <= bottom && left <= right){
            for(int i = left ; i <= right ; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(int i = top ; i <= bottom ; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(top <= bottom){
                for(int i = right ; i >= left ; i--){
                    ans.push_back(matrix[bottom][i]);
                }
            }
            bottom--;
            if(left <= right){
                for(int i = bottom ; i >= top ; i--){
                    ans.push_back(matrix[i][left]);
                }
            }
            left++;
        }
        return ans;
    }
};
