class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        int idx=0; 
        int merge_start = 0;
        int merge_end = 0;
        for (idx = 0; idx < intervals.size(); idx++) {
            if (intervals[idx][1] >= newInterval[0]) {
                break;
            }
        }

        // Check for merge conflicts
        merge_start = idx;
        while(idx<intervals.size() && intervals[idx][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[idx][0], newInterval[0]);
            newInterval[1] = max(intervals[idx][1], newInterval[1]);
            idx++;
        }

        //Remove the old intervals
        merge_end = idx;
        intervals.erase(intervals.begin()+merge_start, intervals.begin()+merge_end);
        intervals.insert(intervals.begin()+merge_start, newInterval);
        
        return intervals;
    }
};
