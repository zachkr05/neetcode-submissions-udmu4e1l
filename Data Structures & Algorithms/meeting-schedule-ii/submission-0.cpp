/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        

        vector<int> starts;
        vector<int> ends;
        for (auto& i : intervals){
            starts.push_back(i.start);
            ends.push_back(i.end);
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int e = 0;
        int s= 0;
        int max_count = 0;
        int curr_count = 0;
        while(s < intervals.size()){
            
            if(starts[s]<ends[e]){
                
                curr_count++;
                s++;

            } else{ //s>=e
                curr_count--;
                e++;
            }

            max_count = max(curr_count, max_count);

        }

        return max_count;
    }
};
