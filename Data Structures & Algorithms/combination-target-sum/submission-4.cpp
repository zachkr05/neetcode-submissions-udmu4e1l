class Solution {


private: 

    vector<vector<int>> res;
    vector<int> candidates;

    void dfs(int idx, vector<int> curr, int remaining){

        //base cases
        if (remaining<0){
            return;
        } 

        if (remaining == 0){
            res.push_back(curr);
            return;
        }

        for (int i = idx; i<candidates.size(); i++){

            int rem = remaining - candidates[i];
            curr.push_back(candidates[i]);
            dfs(i, curr, rem);
            //backtrack
            curr.pop_back();

        }

        return;

    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        candidates = nums;

        vector<int> curr;

        dfs(0, curr, target);

        return res;
        
        
    }
};
