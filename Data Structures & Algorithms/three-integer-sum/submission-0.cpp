class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        //holds the response
        vector<vector<int>> res;
        
        //Sort the array
        sort(nums.begin(), nums.end());

        for (int i = 0; i<nums.size(); i++){ //*
            
            int curr_num = nums[i];
            
            //Ensure we are not using a duplicate
            if(i > 0 && nums[i-1] == curr_num){
                continue;
            }
            
            //Find the next two numbers
            int l = i+1;
            int r = nums.size()-1;

            while(l<r){
                int curr_sum = curr_num + nums[l] + nums[r];
                printf("curr_sum: %d \n", curr_sum);
                // Since it is sorted, we can increase or decrease the current sum by 
                // the index of the left and right pointers
                if(curr_sum<0){
                    printf("Moving left pointer \n");
                    l++;
                } else if(curr_sum > 0){
                    printf("Moving right pointer \n");
                    r--;
                } else{ //Otherwise, it is zero
                    printf("inside else");
                    vector<int> curr_ans;
                    curr_ans.push_back(curr_num);
                    curr_ans.push_back(nums[l]);
                    curr_ans.push_back(nums[r]);
                    res.push_back(curr_ans);
                    //Find a new number
                    l++;

                    //Ensure we are not using a duplicate
                    while (nums[l] == nums[l-1] && l<r){
                        l++;
                    }
                }

            }

            
        }

        return res;
            
    }
};
