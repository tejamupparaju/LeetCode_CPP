/*
739. Daily Temperatures

Given a list of daily temperatures, produce a list that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list temperatures = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].

Companies
Google
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector <int> result (temperatures.size(), 0);
        std::vector<vector <int>> stack;
        std::vector <int> temp;
        
        for(int i=0; i < temperatures.size(); i++){
            while (!stack.empty() && stack.back().back() < temperatures[i]){
                temp = stack.back();
                stack.pop_back();
                result[temp.front()] = i-temp.front();
            }
            
            std::vector<int> temp = {i, temperatures[i]};
            stack.push_back(temp);
        }
        
        return result;
        
    }
};