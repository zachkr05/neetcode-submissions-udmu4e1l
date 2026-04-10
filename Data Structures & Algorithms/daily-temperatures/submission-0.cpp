class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        vector<int> result(temperatures.size(), 0);

        stack<pair<int, int>> stack; //temp, index
        

        for (int i = 0; i<temperatures.size(); i++){
            int curr_temp = temperatures[i];

            while(!stack.empty() && curr_temp>stack.top().first){
                auto pair_val = stack.top();
                stack.pop();
                result[pair_val.second] = i - pair_val.second ;
            }
            stack.push(pair<int,int>(curr_temp, i));
        }

        return result;
    }
};
