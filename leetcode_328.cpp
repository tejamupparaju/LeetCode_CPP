/*
328. Odd Even Linked List

Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
The first node is considered odd, the second node even and so on ...
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
    ListNode* oddEvenList(ListNode* head) {
        if (! head || ! head->next){
            return head;
        }
        
        ListNode *even = head->next, *odd = head, *teven = head->next;
        
        int counter = 3;
        for (ListNode* node=head->next->next; node; node = node->next){
            if (counter % 2 == 0){
                even->next = node;
                even = even->next;
            }
            else{
                odd->next = node;
                odd = odd->next;
            }
            
            counter += 1;
        }
        
        odd->next = teven;
        even->next = NULL;
        
        return head;
        
    }
};