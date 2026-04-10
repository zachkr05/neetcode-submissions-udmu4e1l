class Solution {
public:
    int maxArea(vector<int>& heights) {


        //two ptr solution
        size_t l = 0;
        size_t r = heights.size()-1;
        int curr_area = 0;
        int res = 0;
        
        while(l<r){
            int left_height = heights[l];
            int right_height = heights[r];
            int width = r-l;

            //left's height is the limiting factor
            if(left_height<right_height){
                curr_area = left_height * width;
                l++; // Take a greedy step with left ptr 
            } else{
                curr_area = right_height * width;
                r--;
            }

            if(curr_area>res){
                res = curr_area;
            }
        }

        return res;
        
        
    }
};
