class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int s = 1;
        int e = INT_MIN;
        for(int i = 0; i<n; i++){
            if(piles[i] > e){
                e = piles[i];
            }
        }
        int mid = 0;
        int ans = INT_MAX;

        while(s <= e){
            mid = s + (e-s)/2;
            long long count = 0;
            for(int i = 0; i< n; i++){
                count += (piles[i] + mid - 1)/mid;
                }
                if(count <= h){
                    e = mid - 1;
                    ans = min(mid,ans);
                    
                }
                else{
                    s = mid + 1;
                }

            }
        return ans;
    }
};
