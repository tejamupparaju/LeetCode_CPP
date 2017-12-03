/*
 57. Insert Interval

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Companies 
Google Facebook LinkedIn 
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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        vector<Interval>::iterator iter;
        for(iter=intervals.begin(); iter != intervals.end(); iter++){
            if(iter->end < newInterval.start){
                result.push_back(*iter);
            }
            else if(newInterval.end < iter->start){
                result.push_back(newInterval);
                for(vector<Interval>::iterator iter1=iter;  iter1 != intervals.end(); iter1++){
                    result.push_back(*iter1);
                }
                return result;
            }
            else{
                newInterval.start = std::min(newInterval.start, iter->start);
                newInterval.end = std::max(newInterval.end, iter->end);
            }
            
        }
        result.push_back(newInterval);
        return result;
    }
};