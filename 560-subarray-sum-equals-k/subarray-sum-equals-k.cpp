class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        // Stores: prefix_sum -> how many times this prefix_sum has appeared
        unordered_map<int, int> mp;

        // Prefix sum = 0 has appeared once before we start
        // This handles subarrays that start from index 0
        mp[0] = 1;

        int prefixSum = 0;  // Keeps track of current prefix sum
        int count = 0;      // Stores number of subarrays whose sum is k

        for (int num : nums) {

            // Add current element to prefix sum
            prefixSum += num;

            // We need an earlier prefix sum = prefixSum - k
            // Because:
            // current prefixSum - old prefixSum = k
            // old prefixSum = current prefixSum - k
            if (mp.find(prefixSum - k) != mp.end()) {

                // Add how many times that required prefix sum
                // has already occurred
                count += mp[prefixSum - k];
            }

            // Store/increase the frequency of current prefix sum
            mp[prefixSum]++;
        }

        // Return total number of subarrays having sum exactly k
        return count;
    }
};