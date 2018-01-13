/*
2. Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode* root = new ListNode(0), *troot = NULL;
        troot = root;
        int buffer = 0, temp;
        while (l1 || l2){
            ListNode* node = new ListNode(0);
            root->next = node;
            root = root->next;
            temp = (l1) ? l1->val : 0; 
            temp += (l2) ? l2->val : 0;
            temp += buffer;
            buffer = 0;
            
            if (temp > 9){
                root->val = temp % 10;
                buffer = 1;
            }
            else{
                root->val = temp;
            }
            l1 = (l1) ? l1->next : l1;
            l2 = (l2) ? l2->next : l2;
        }
        if (buffer){
            ListNode* node = new ListNode(1);
            root->next = node;
            root = root->next;
        }
        
        return troot->next;
    }
};