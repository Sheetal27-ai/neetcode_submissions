class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        unordered_set <int> s;
        for( int num : nums){
            s.insert(num);
        }

       
        int longest = INT_MIN;
        for(int num : s){
            // to find the beginning number
            if(s.count(num-1) == 0){
               int current = num;
               int count = 1;

               while(s.count(current + 1)){
                count ++;
                current ++;
               } 

               longest = max(longest,count);
            }

           

        }

        return longest;
    }
};
