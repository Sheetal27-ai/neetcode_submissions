class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }

        int n = s.length();
        for(int i=0; i < n-1; i++){
            for(int j=0; j < n-1-i; j++){
            if(s[j] > s[j+1]){
                swap(s[j],s[j+1]);
            }
            }
            
        }
         for(int i=0; i < n-1; i++){
            for(int j=0; j < n-1-i; j++){
            if(t[j] > t[j+1]){
                swap(t[j],t[j+1]);
            }
            }
            
        }
        for(int i=0; i < n; i++){
            if(s[i] != t[i]){
                return false;
            }
        }
        return true;
    }
};
