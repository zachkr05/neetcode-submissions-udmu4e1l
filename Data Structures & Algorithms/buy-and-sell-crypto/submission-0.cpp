class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int min_value = prices[0];
        int max_profit = 0;
        int curr_profit = 0;
        for (size_t i = 0; i<prices.size(); i++){
            
            if (prices[i]<min_value){
                min_value = prices[i];
            }

            curr_profit = prices[i]-min_value;

            if(curr_profit>max_profit){
                max_profit = curr_profit;
            }

        }

        return max_profit;


    }
};
