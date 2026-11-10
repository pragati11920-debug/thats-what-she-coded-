class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        // Initialize two pointers
        int i = 0;                  // Starts from the beginning
        int j = nums.size() - 1;    // Starts from the end

        // Continue until the pointers cross
        while (i <= j) {

            // If nums[i] is valid, keep it
            if (nums[i] != val) {
                i++;
            }

            else {
                // Check if the right element is valid
                if (nums[j] != val) {

                    // Replace unwanted element with valid element
                    nums[i] = nums[j];
                    j--;
                }

                // If right element is also unwanted, skip it
                else {
                    j--;
                }
            }
        }

        // i represents the number of valid elements
        return i;
    }
};