class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Step 1: Count frequencies
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Create buckets
        vector<vector<int>> bucket(nums.size() + 1);

        // Step 3: Place elements into their frequency bucket
        for (auto &it : freq) {
            bucket[it.second].push_back(it.first);
        }

        // Step 4: Collect top k frequent elements
        vector<int> ans;

        for (int i = nums.size(); i >= 1 && ans.size() < k; i--) {
            for (int num : bucket[i]) {
                ans.push_back(num);
                if (ans.size() == k)
                    return ans;
            }
        }

        return ans;
    }
};