class Solution {
private:
    void findSubsets(int idx, vector <int> arr,   vector<vector<int>> &ans, vector<int> val){
        // base case
        if(idx >= arr.size()){
            ans.push_back(val);
            return;
        }

        val.push_back(arr[idx]);
        findSubsets(idx+1, arr, ans, val);
        val.pop_back();
        findSubsets(idx+1, arr, ans, val);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector <int> val;
        findSubsets(0, nums, ans, val);
        return ans;
    }
};
