class Solution {

private:

    vector<vector<int>> res;
    vector<int> candidates;

    void dfs(int idx, vector<int>& curr, int remaining){

        
        if (remaining<0){
            //curr.pop_back();
            return;
        }

        if (remaining == 0){
                res.push_back(curr);
        }

        for(int i = idx; i<candidates.size(); i++){

            int remainder = remaining - candidates[i];
            curr.push_back(candidates[i]);
            
            dfs(i, curr, remainder);

            curr.pop_back();

        }

        return;


    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        candidates = nums;
        dfs(0, curr, target);
        return res;
    }
};
