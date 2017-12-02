/*
252. Meeting Rooms

Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return false.

Companies 
Facebook 

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
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.size() == 0){
            return true;
        }
        std::sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
        
        std::vector<Interval>::iterator iter;
        Interval current = intervals[0];
        std::cout<< current.start << std::endl;
        std::cout << current.end << std::endl;
        
        for(iter=intervals.begin()+1; iter != intervals.end(); iter++){
            if (current.end > iter->start) return false;
            
            current = *iter;
        }
        
        return true;        
    }
};