class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int window_size = s1.length();
        if( window_size > s2.length()){
            return false;
        }
// counting characters in s1
        int freq1[26] = {0};
        for(int i=0; i<s1.length(); i++){
            freq1[s1[i] - 'a']++;
        }
    // for the first window
    int freq2[26] = {0};
        
        for(int i=0; i < window_size; i++){
            freq2[s2[i] - 'a']++;
        }
        int left = 0;
        int right = window_size - 1;

        while(right < s2.length()){
            bool same = true;
            for(int i=0; i<26; i++){
            if(freq1[i] != freq2[i]){
                same = false;
                break;
            }
            }
            if(same){
                return true;
            }
            freq2[s2[left] - 'a']--;
            left++;
            right++;
            if(right < s2.length()){
                freq2[s2[right] - 'a']++;
            }
        }
        return false;
    }
};
