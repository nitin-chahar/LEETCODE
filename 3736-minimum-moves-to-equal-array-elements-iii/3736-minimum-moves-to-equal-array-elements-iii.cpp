class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int moves = 0, n = nums.size();
        for(int num : nums){
            moves += (nums[n-1] - num);
        }

        return moves;
    }
};