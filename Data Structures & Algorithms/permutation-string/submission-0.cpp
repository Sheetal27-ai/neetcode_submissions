class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int window_size = s1.length();
        int freq1[26] = {0};
        int left = 0;
        int right = window_size - 1;
        for(int i = 0; i < s1.length(); i++){
            freq1[s1[i] - 'a']++;
        }
         
        
        int diff[26] = {0};

        for( left = 0 ; right < s2.length();){
            int start = left;
            int freq2[26] = {0};
            while(start <= right){
                freq2[s2[start] - 'a']++;
                start ++;    
            }
            
            start = left;
            for(int i = 0; i<26; i++){
                diff[i] = freq2[i] - freq1[i];
            }

            bool allzero = true;
            for(int i=0; i < 26; i++){
                if(diff[i] != 0){
                    allzero = false;
                    break;
                }
            }
            if(allzero){
                return true;
            }

            left ++;
            right++;
            
        }

        return false;
    }
};
