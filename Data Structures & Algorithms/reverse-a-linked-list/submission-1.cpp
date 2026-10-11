/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reverse(ListNode* &prev, ListNode* &head, ListNode* &curr){
        if(curr == NULL){
            head = prev;
            return ;
        }
        ListNode* forward = curr->next;
        reverse(curr,head,forward);
        curr->next = prev;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev= NULL;
        ListNode* curr = head;
        reverse(prev,head,curr);
        return head;
    }
};
