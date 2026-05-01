class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        

        vector<vector<int>>res;
        int n = intervals.size();
        int i = 0;


        //edge case NEWINTERVAL begins after old ones end
        while(i<n && newInterval[0] > intervals[i][1] ){
            res.push_back(intervals[i]);
            i++;
        }

        //edge case NEWINTERVAL ends after old ones begin
        while(i < n && newInterval[1] >= intervals[i][0]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);

        //add whats left over
        while(i<n) {
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};
