class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack <int> s;
        int n = heights.size();
        int maxArea = 0;
        vector <int> leftMin(n,-1);
        vector <int> rightMin(n,n);
        for(int i = 0; i < heights.size(); i++){
            while(!s.empty() && heights[s.top()] >= heights[i] ){
                s.pop();
            }
            if(!s.empty()){
                leftMin[i] = s.top();
            }
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }

        for(int i = n - 1; i >= 0; i--){
            while(!s.empty() && heights[s.top()] >= heights[i] ){
                s.pop();
            }
            if(!s.empty()){
                rightMin[i] = s.top();
            }
            s.push(i);
        }

        for(int i = 0; i < heights.size(); i++){
            int area = heights[i]*(rightMin[i] - leftMin[i] - 1);
            maxArea = max(maxArea, area);
        }

        return maxArea;

    }
};
