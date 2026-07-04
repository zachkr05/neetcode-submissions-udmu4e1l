class Solution {
public:
    int rob(vector<int>& nums) {


        int rob1 = 0;
        int rob2=0;
        

        for (int i = 0; i<nums.size(); i++ ){
            int new_num = nums[i];
            int temp = max(new_num+rob1, rob2);
            rob1=rob2;
            rob2=temp;
        } //O(n)

        return rob2;        
    }
};
