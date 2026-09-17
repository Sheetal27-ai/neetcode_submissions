class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = n - 1;

        while(s < e){
            int mid = s + (e-s)/2;
            if(nums[mid] > nums[e]) s = mid + 1;
            else e = mid;
        }
        int rt_s = s;
        int rt_e = n-1;
        while(rt_s <= rt_e){
            int mid = rt_s + (rt_e - rt_s)/2;
            if(nums[mid] == target) return mid;
            else if(target > nums[mid]) rt_s = mid + 1;
            else rt_e = mid - 1;
        }
        int lt_s = 0;
        int lt_e = s-1;
        while(lt_s <= lt_e){
            int mid = lt_s + (lt_e - lt_s)/2;
            if(nums[mid] == target) return mid;
            else if(target > nums[mid]) lt_s = mid + 1;
            else lt_e = mid - 1;
        }
        return -1;
    }
};
