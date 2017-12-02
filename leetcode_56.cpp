/*
 56. Merge Intervals
 
 Given a collection of intervals, merge all overlapping intervals.
 
 For example,
 Given [1,3],[2,6],[8,10],[15,18],
 return [1,6],[8,10],[15,18].
 
 Companies
 Google Facebook Microsoft Bloomberg LinkedIn Twitter Yelp
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if (intervals.size() == 0){
            return result;
        }
        
        std::sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
        Interval current = intervals[0];
        
        for(int i=1; i<intervals.size(); i++){
            if (current.end >= intervals[i].start){
                current.end = std::max(intervals[i].end, current.end);
                
            }
            else{
                result.push_back(current);
                current = intervals[i];
            }
            
        }
        
        result.push_back(current);
        return result;
    }
};
