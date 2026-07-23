class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<string> t = strs;
        vector<vector<string>> ans;
        vector<bool> visited(n,false);

        for(int i=0; i < t.size(); i++){
            for(int j=0; j < t[i].length(); j++){
                for(int k=0; k < t[i].length()-j-1;k++ ){
                    if(t[i][k]> t[i][k+1]){
                        swap(t[i][k],t[i][k+1]);
                    }
                }
            }
        }
        
        for(int i=0; i < t.size(); i++){
            if(visited[i]){
                continue;
            }
            vector <string> group;
            for(int j=0; j < t.size(); j++){
                if(t[i] == t[j]){
                    group.push_back(strs[j]);
                    visited[j] = true;

                }
            }
            ans.push_back(group);
        }

        return ans;
        
    }
};
