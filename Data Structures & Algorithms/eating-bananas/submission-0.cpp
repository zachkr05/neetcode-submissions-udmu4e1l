class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        

        //Binary search problem

        //cost function


        int left = 1;
        int right= *max_element(piles.begin(), piles.end());

        int res = right;


        while(left<=right){

            //find the mid point
            int mid = left + (right-left)/2;
            
            //Calculate the total time 
            long long totalTime = 0;
            for(int p : piles){
                totalTime += ceil(static_cast<double>(p) / mid); //dont truncate
            }

            if (totalTime<=h){
                res = mid;
                right = mid -1;
            } else {
                left = mid+1;
            }
        }

        return res;
    }
};
