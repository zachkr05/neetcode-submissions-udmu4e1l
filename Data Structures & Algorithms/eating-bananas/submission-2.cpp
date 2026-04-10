class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        //k must be  min(piles) <= k <= max(piles)

        //Binary search from [min(piles), min(piles)-1, ... , max(piles)+1, max(piles)]

        int left = 1;
        int right = *std::max_element(piles.begin(), piles.end());
        int res = right;

        while(left<=right){
            int k = left + ( right - left) / 2;
            int time = 0;
            for (auto& pile : piles){ // calc the time it took
                time+=(int) std::ceil((double)pile/k);
            }

            if (time <= h){
                res = std::min(res, k);
                right = k-1;
            } 
            else{
                left = k +1;
            }
        }

        return res;

    }
};
