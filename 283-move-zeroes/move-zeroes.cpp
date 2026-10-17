class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> temp;

        // Store all non-zero elements
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                temp.push_back(nums[i]);
            }
        }

        // Copy non-zero elements back into nums
        for (int i = 0; i < temp.size(); i++) {
            nums[i] = temp[i];
        }

        // Fill remaining positions with zeroes
        for (int i = temp.size(); i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};