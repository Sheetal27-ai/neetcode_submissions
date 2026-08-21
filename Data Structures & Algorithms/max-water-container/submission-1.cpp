class Solution {
public:
    int maxArea(vector<int>& heights) {
        int leftptr = 0;
        int rightptr = heights.size() - 1;
        int maxArea = INT_MIN;
        
        while(leftptr < rightptr){
            int area = (rightptr - leftptr)*min(heights[leftptr],              heights[rightptr]);
            maxArea = max(maxArea,area);

            
            if(heights[leftptr] < heights[rightptr]){
                leftptr++;
            }
            else{
                rightptr--;
            }

        }
        return maxArea;
    }
};
