/*
448. Find All Numbers Disappeared in an Array

Given an array of integers where 1 <= a[i] <= n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]

Companies 
Google 


MOWN Solution
since 1 <= a[i] <= n we can multiply the abs(number at index nums[i]) with -1
now look for nums < 0

*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        int index;
        
        for(int i=0; i<nums.size(); i++){
            index = abs(nums[i]) - 1;
            nums[index] = abs(nums[index])* -1;
        }
        
        for(int i=0; i<nums.size(); i++){
            if (nums[i] > 0)
            result.push_back(i+1);
        }
        return result;
        
    }
};