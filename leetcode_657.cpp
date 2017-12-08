/*
657. Judge Route Circle

Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.

The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L (Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.

Example 1:
Input: "UD"
Output: true
Example 2:
Input: "LL"
Output: false

Companies 
Google
*/
// MOWN solution, use map and then check if no.of U == no.of D and no.of L's == no.of R's

#include <map>
class Solution {
public:
    bool judgeCircle(string moves) {
        
        std::map<char, int>mapr;
        for(int i=0; i<moves.length(); i++){
            if (mapr.find(moves[i]) != mapr.end()){
                mapr[moves[i]] += 1;
            }
            else{
                mapr[moves[i]] = 1;
            }           
        }
        
        if ((mapr.find('U') != mapr.end() && mapr.find('D') == mapr.end()) || (mapr.find('U') == mapr.end() && mapr.find('D') != mapr.end())){
            return false;
        }
        
        if ((mapr.find('L') != mapr.end() && mapr.find('R') == mapr.end()) || (mapr.find('L') == mapr.end() && mapr.find('R') != mapr.end())){
            return false;
        }
        
        if (mapr.find('U') != mapr.end() && mapr['U'] != mapr['D']){
            return false;
        }
        
        if (mapr.find('R') != mapr.end() && mapr['R'] != mapr['L']){
            return false;
        }
        
        return true;
        
        
    }
};


// LUP solution to use switch

class Solution {
public:
    bool judgeCircle(string moves) {
        int horizontal = 0;
        int vertical = 0;
        
        for(char ch: moves){
            switch (ch) {
                case 'U':
                    vertical++;
                    break;
                case 'D':
                    vertical--;
                    break;
                case 'R':
                    horizontal++;
                    break;
                    
                case 'L':
                    horizontal--;
                    break;
                    
            }
        }
        return vertical == 0 && horizontal== 0;
        
    }
};
