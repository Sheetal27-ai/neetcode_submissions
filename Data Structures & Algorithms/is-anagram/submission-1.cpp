class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        int n=s.length();
        int index;
        int arr[26]= {0};
        for(int i=0; i < n; i++ ){
            index = s[i] - 'a';
            arr[index]++;
        }
         for(int i=0; i < n; i++ ){
            index = t[i] - 'a';
            arr[index]--;
        }
        for(int i=0; i<26; i++){
        if(arr[i] != 0){
            return false;
        }
        }
        return true;;
    }
};
