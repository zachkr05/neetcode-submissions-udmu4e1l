class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string prefix = strs[0];
        //keep track of the num of chars similar
        int curr_length=prefix.size();
        size_t temp_length = 0;
        //loop thru every string besides the first in the array
        for(size_t i=1; i<strs.size(); i++){
            
            //loop thru each char of the current string
            for (size_t j=0;j<prefix.size();j++ ){
                if (j==0){
                    temp_length=0;
                }
                if (prefix[j]!=strs[i][j]) break;
                temp_length++;
            }
            if (temp_length<curr_length){
                curr_length=temp_length;
            }
            

        }

        string ans="";

        for (size_t i=0; i<curr_length; i++){
            ans+=prefix[i];
        }

        return ans;

    }
};