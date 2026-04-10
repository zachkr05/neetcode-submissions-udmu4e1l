class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        //Convert our nums array to a set
        set<int> set;
        for(size_t i=0; i<nums.size(); i++){
            set.insert(nums[i]);
        }
        //set.contains(1);
        int res = 0;
        //loop thru each number
        for (auto& num : nums){

            //check if the current number is the begging of a sequence
            if(set.count(num-1)==0){ //if it does not have a left hand side neighbor
                
                int curr_length=0;
                //loop thur the rest of the possible numbers
                while(set.count(num+curr_length)>0){
                    curr_length++;
                }
                printf("%d",curr_length);
                res = max(res,curr_length);
            }

        }

        return res;
    }
};
