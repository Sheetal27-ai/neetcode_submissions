class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int largest = 0;
        int maxi = 0;
        string temp = "";
        for(int i=0; i < s.length(); i++){
            if(count(temp.begin(), temp.end(),s[i]) > 0){
                maxi = max(maxi,largest);
                while(count(temp.begin(), temp.end(),s[i]) > 0){
                    temp.erase(temp.begin());
                    largest--;
                }
                
            }
            temp += s[i];
            largest++;
           
        }
        maxi = max(maxi, largest);
        return maxi;
    }
};
