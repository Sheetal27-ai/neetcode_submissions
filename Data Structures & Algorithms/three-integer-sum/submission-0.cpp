class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> temp;

        for(int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            unordered_set<int> s;

            for(int j = i + 1; j < nums.size(); j++) {
                int toFind = target - nums[j];

                if(s.find(toFind) != s.end()) {
                    vector<int> trip = {nums[i], nums[j], toFind};
                    sort(trip.begin(), trip.end());
                    temp.insert(trip);
                }

                s.insert(nums[j]);
            }
        }

        vector<vector<int>> ans;

        for(vector<int> num : temp) {
            ans.push_back(num);
        }

        return ans;
    }
};