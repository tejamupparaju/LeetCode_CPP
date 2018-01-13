/*
445. Add Two Numbers II

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> nums1, nums2;
        for(ListNode* node=l1; node; node=node->next)
            nums1.push_back(node->val);
            
        
        for(ListNode* node=l2; node; node=node->next)
            nums2.push_back(node->val);
        
        int len1 = nums1.size(), len2 = nums2.size(), carry=0, current=0;
        ListNode *root=NULL, *new_node=NULL;
        
        for(int i=len1-1, j=len2-1; i >=0 || j >= 0 || carry > 0; i--, j--){
            current = carry;
            if (i>=0)
                current += nums1[i];
            
            if (j>=0)
                current += nums2[j];
            
            carry = current/10;
            current = current%10;
            
            new_node = new ListNode(current);
            new_node->next = root;
            root = new_node;
        }
           
        return root;
    }
};